
#include "ccleanup.h"

SEXP R_ExecWithCleanup(SEXP (*fun)(void *), void *data,
		       void (*cleanfun)(void *), void *cleandata);

struct arg_data {
  int num;
  SEXP ptr[10];			/* TODO: dynamically allocate */
};

SEXP testfunc(SEXP arg1, SEXP arg2) {
  return ScalarInteger(42);
}

SEXP wrapper2(void *data) {
  struct arg_data *adata = data;
  return testfunc(adata->ptr[0], adata->ptr[1]);
}

void cleaner(void *cleandata) {
  /* Note that this is called no matter what, so you need a way
     signal normal (= not error) exit. */
  REprintf("Cleaning up\n");
}

SEXP wrapper1(SEXP arg1, SEXP arg2) {
  struct arg_data adata;
  adata.num = 2;
  adata.ptr[0] = arg1;
  adata.ptr[1] = arg2;
  return R_ExecWithCleanup(&wrapper2, &adata, &cleaner, 0);
}

static const R_CallMethodDef callMethods[]  = {
  { "wrapper1", (DL_FUNC) wrapper1, 0 },
  { NULL, NULL, 0 }
};

void R_init_ccleanup(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
