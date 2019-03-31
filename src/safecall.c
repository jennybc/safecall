
#include <R.h>
#include <Rinternals.h>
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

/* --------------------------------------------------------------------- */

struct cleanup_record {
  void (*func)(void*);
  void *data;
};

struct cleanup_data {
  struct cleanup_record *recs;
  int size;
  int next;
};

static struct cleanup_data *active_cleanup_data = 0;

void on_exit_reg(void (*func)(void*), void *data) {
  static struct cleanup_data *acd;
  int size;
  int next;

  acd = active_cleanup_data;
  size = acd->size;
  next = acd->next;

  if (next == size) error("Cleanup stack full");

  acd->recs[next].func = func;
  acd->recs[next].data = data;
  acd->next ++;
}

/* -------------------------------------------------------------------- */

struct argdata {
  DL_FUNC fun;
  SEXP numpar;
  SEXP args;
};

SEXP wrap_unpack(void *data);
void cleanup(void *data);

SEXP c_safecall(SEXP addr, SEXP numpar, SEXP args) {
  struct Rf_RegisteredNativeSymbol *tmp = R_ExternalPtrAddr(addr);
  DL_FUNC fun = tmp->symbol.call->fun;
  SEXP result = R_NilValue;

  struct argdata argd = { fun, numpar, args };
  struct cleanup_data *old = active_cleanup_data;
  struct cleanup_record recs[100];
  struct cleanup_data new = { recs, 100, 0 };

  active_cleanup_data = &new;

  result = R_ExecWithCleanup(wrap_unpack, &argd, cleanup, 0);

  active_cleanup_data = old;

  return result;
}

SEXP wrap_unpack(void *data) {
  struct argdata *argd = data;
  DL_FUNC fun = argd->fun;
  int num = INTEGER(argd->numpar)[0];
  SEXP args = argd->args;
  SEXP retval;

#define X(i) VECTOR_ELT(args, i)

  if (num > 10) error("Too many arguments");

  switch (num) {
  case 0:
    retval = fun();
    break;
  case 1:
    retval = fun(X(0));
    break;
  case 2:
    retval = fun(X(0), X(1));
    break;
  case 3:
    retval = fun(X(0), X(1), X(2));
    break;
  case 4:
    retval = fun(X(0), X(1), X(2), X(3));
    break;
  case 5:
    retval = fun(X(0), X(1), X(2), X(3), X(4));
    break;
  case 6:
    retval = fun(X(0), X(1), X(2), X(3), X(4), X(5));
    break;
  case 7:
    retval = fun(X(0), X(1), X(2), X(3), X(4), X(5), X(6));
    break;
  case 8:
    retval = fun(X(0), X(1), X(2), X(3), X(4), X(5), X(6), X(7));
    break;
  case 9:
    retval = fun(X(0), X(1), X(2), X(3), X(4), X(5), X(6), X(7), X(8));
    break;
  case 10:
    retval = fun(X(0), X(1), X(2), X(3), X(4), X(5), X(6), X(7), X(8), X(9));
    break;
  }

#undef X

  return retval;
}

void cleanup(void *data) {
  static struct cleanup_data *acd;
  int size;
  int next;

  acd = active_cleanup_data;
  size = acd->size;
  next = acd->next;

  while (next > 0) {
    next--;
    acd->recs[next].func(acd->recs[next].data);
  }
}
