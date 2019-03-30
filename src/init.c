
#include <R.h>
#include <Rinternals.h>

SEXP testfunc1(SEXP, SEXP);
SEXP testfunc2(SEXP, SEXP);

SEXP c_safecall(SEXP, SEXP, SEXP);

static const R_CallMethodDef callMethods[]  = {
  { "testfunc1",  (DL_FUNC) testfunc1,  2 },
  { "testfunc2",  (DL_FUNC) testfunc2,  2 },
  { "c_safecall", (DL_FUNC) c_safecall, 3 },
  { NULL, NULL, 0 }
};

void R_init_safecall(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
