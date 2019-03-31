
#include "safecall.h"

SEXP testfunc1(SEXP, SEXP);
SEXP testfunc2(SEXP, SEXP);
SEXP testfunc3(SEXP);

static const R_CallMethodDef callMethods[]  = {
  { "testfunc1",  (DL_FUNC) testfunc1,  2 },
  { "testfunc2",  (DL_FUNC) testfunc2,  2 },
  { "testfunc3",  (DL_FUNC) testfunc3,  1 },
  SAFECALL_REGISTRATION_RECORD,
  { NULL, NULL, 0 }
};

void R_init_safecall(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
  R_RegisterCCallable("safecall", "r_on_exit", (DL_FUNC) r_on_exit_reg);
}
