
#include "ccleanup.h"

struct arg_data {
  int num;
  SEXP ptr[10];			/* TODO: dynamically allocate */
};

struct cleanup_record {
  void (*func)(void*);
  void *ptr;
};

struct cleanup_record cleanup_records[100]; /* TODO: dynamically allocate? */

/* --------------------------------------------------------------------- */

SEXP testfunc1(SEXP arg1, SEXP arg2) {
  return ScalarInteger(42);
}

SEXP wrapper1(void *data) {
  struct arg_data *adata = data;
  return testfunc1(adata->ptr[0], adata->ptr[1]);
}

void cleaner1(void *cleandata) {
  /* Note that this is called no matter what, so you need a way
     signal normal (= not error) exit. */
  REprintf("Cleaning up\n");
}

SEXP xwrapper1(SEXP arg1, SEXP arg2) {
  struct arg_data adata;
  adata.num = 2;
  adata.ptr[0] = arg1;
  adata.ptr[1] = arg2;
  return R_ExecWithCleanup(&wrapper1, &adata, &cleaner1, 0);
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

static const R_CallMethodDef callMethods[]  = {
  { "xwrapper1", (DL_FUNC) xwrapper1, 0 },
  { "xwrapper2", (DL_FUNC) xwrapper2, 0 },
  { NULL, NULL, 0 }
};

void R_init_ccleanup(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
