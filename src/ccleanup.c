
#include "ccleanup.h"
#include <R_ext/Rdynload.h>

typedef struct {
    char       *name;
    DL_FUNC     fun;
    int         numArgs;

    R_NativePrimitiveArgType *types;
} Rf_DotCSymbol;

typedef Rf_DotCSymbol Rf_DotFortranSymbol;

typedef struct {
    char       *name;
    DL_FUNC     fun;
    int         numArgs;
} Rf_DotCallSymbol;

typedef Rf_DotCallSymbol Rf_DotExternalSymbol;

struct Rf_RegisteredNativeSymbol {
    NativeSymbolType type;
    union {
	Rf_DotCSymbol        *c;
	Rf_DotCallSymbol     *call;
	Rf_DotFortranSymbol  *fortran;
	Rf_DotExternalSymbol *external;
    } symbol;
    DllInfo *dll;
};

struct cleanup_record {
  void (*func)(void*);
  void *ptr;
};

struct arg_data {
  struct cleanup_record *rec;
  int num;
  SEXP ptr[10];			/* TODO: dynamically allocate */
};

void cleaner(void *cleandata) {
  /* Note that this is called no matter what, so you need a way
     signal normal (= not error) exit. */
  REprintf("Cleaning up\n");
}

void register_cleanup(void (*cleanfun)(void *), void *data) {
  /* TODO */
}

void cleanup_free(void *data) {
  REprintf("cleanup_free()\n");
  free(data);
}

/* --------------------------------------------------------------------- */

SEXP testfunc1(struct cleanup_record *rec, SEXP arg1, SEXP arg2) {
  int *foo = malloc(100);
  register_cleanup(cleanup_free, foo);
  return ScalarInteger(42);
}

SEXP wrapper1(void *data) {
  struct arg_data *adata = data;
  return testfunc1(adata->rec, adata->ptr[0], adata->ptr[1]);
}

SEXP xwrapper1(SEXP arg1, SEXP arg2) {
  struct cleanup_record recs[101]; /* TODO: dynamically allocate */
  struct arg_data adata;
  adata.num = 2;
  adata.rec = recs;
  adata.ptr[0] = arg1;
  adata.ptr[1] = arg2;
  return R_ExecWithCleanup(&wrapper1, &adata, &cleaner, 0);
}

/* --------------------------------------------------------------------- */

SEXP testfunc2(SEXP arg1, SEXP arg2) {
  error("oops");
  return R_NilValue;
}

SEXP wrapper2(void *data) {
  struct arg_data *adata = data;
  return testfunc2(adata->ptr[0], adata->ptr[1]);
}

void cleaner2(void *cleandata) {
  /* Note that this is called no matter what, so you need a way
     signal normal (= not error) exit. */
  REprintf("Cleaning up 2\n");
}

SEXP xwrapper2(SEXP arg1, SEXP arg2) {
  struct arg_data adata;
  adata.num = 2;
  adata.ptr[0] = arg1;
  adata.ptr[1] = arg2;
  return R_ExecWithCleanup(&wrapper2, &adata, &cleaner2, 0);
}

/* -------------------------------------------------------------------- */

SEXP xcalltest(SEXP ptr, SEXP args) {
  static SEXP native_symbol = NULL;
  static SEXP registered_native_symbol = NULL;
  DL_FUNC fun = 0;
  if (native_symbol == NULL) {
    native_symbol = install("native symbol");
    registered_native_symbol = install("registered native symbol");
  }
  if (R_ExternalPtrTag(ptr) == native_symbol) {
    fun = R_ExternalPtrAddrFn(ptr);
    return fun(VECTOR_ELT(args, 0), VECTOR_ELT(args, 1));
  } else if(R_ExternalPtrTag(ptr) == registered_native_symbol) {
    struct Rf_RegisteredNativeSymbol *tmp = R_ExternalPtrAddr(ptr);
    fun = tmp->symbol.call->fun;
    return fun(VECTOR_ELT(args, 0), VECTOR_ELT(args, 1));
  } else {
    error("Cannot resolve native routine");
  }
  return R_NilValue;
}

static const R_CallMethodDef callMethods[]  = {
  { "xwrapper1", (DL_FUNC) xwrapper1, 2 },
  { "xwrapper2", (DL_FUNC) xwrapper2, 2 },
  { "xcalltest", (DL_FUNC) xcalltest, 2 },
  { NULL, NULL, 0 }
};

void R_init_safecall(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
