
#include "safecall.h"
#include <R_ext/Rdynload.h>

SEXP testfunc1(SEXP, SEXP);
SEXP testfunc2(SEXP, SEXP);
SEXP testfunc3(SEXP);

SEXP testfunc4(SEXP);
SEXP testfunc42();
SEXP testfunc43(SEXP);
SEXP testfunc44();

SEXP argtest0();
SEXP argtest1(SEXP);
SEXP argtest2(SEXP,SEXP);
SEXP argtest3(SEXP,SEXP,SEXP);
SEXP argtest4(SEXP,SEXP,SEXP,SEXP);
SEXP argtest5(SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest6(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest7(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest8(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest9(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);

SEXP argtest10(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest11(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest12(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest13(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP);
SEXP argtest14(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP);
SEXP argtest15(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP);
SEXP argtest16(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP);
SEXP argtest17(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest18(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest19(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest20(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);

SEXP argtest21(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest22(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest23(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest24(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest25(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP);
SEXP argtest26(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP);
SEXP argtest27(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP);
SEXP argtest28(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP);
SEXP argtest29(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP);
SEXP argtest30(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,
	       SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);

static const R_CallMethodDef callMethods[]  = {
  SAFECALL_REGISTRATION_RECORD,

  { "testfunc1",  (DL_FUNC) testfunc1,  2 },
  { "testfunc2",  (DL_FUNC) testfunc2,  2 },
  { "testfunc3",  (DL_FUNC) testfunc3,  1 },

  { "testfunc4",  (DL_FUNC) testfunc4,  1 },
  { "testfunc42", (DL_FUNC) testfunc42, 0 },
  { "testfunc43", (DL_FUNC) testfunc43, 1 },
  { "testfunc44", (DL_FUNC) testfunc44, 0 },

  { "argtest0",   (DL_FUNC) argtest0,   0 },
  { "argtest1",   (DL_FUNC) argtest1,   1 },
  { "argtest2",   (DL_FUNC) argtest2,   2 },
  { "argtest3",   (DL_FUNC) argtest3,   3 },
  { "argtest4",   (DL_FUNC) argtest4,   4 },
  { "argtest5",   (DL_FUNC) argtest5,   5 },
  { "argtest6",   (DL_FUNC) argtest6,   6 },
  { "argtest7",   (DL_FUNC) argtest7,   7 },
  { "argtest8",   (DL_FUNC) argtest8,   8 },
  { "argtest9",   (DL_FUNC) argtest9,   9 },
  { "argtest10",  (DL_FUNC) argtest10, 10 },

  { "argtest11",  (DL_FUNC) argtest11, 11 },
  { "argtest12",  (DL_FUNC) argtest12, 12 },
  { "argtest13",  (DL_FUNC) argtest13, 13 },
  { "argtest14",  (DL_FUNC) argtest14, 14 },
  { "argtest15",  (DL_FUNC) argtest15, 15 },
  { "argtest16",  (DL_FUNC) argtest16, 16 },
  { "argtest17",  (DL_FUNC) argtest17, 17 },
  { "argtest18",  (DL_FUNC) argtest18, 18 },
  { "argtest19",  (DL_FUNC) argtest19, 19 },
  { "argtest20",  (DL_FUNC) argtest20, 20 },

  { "argtest21",  (DL_FUNC) argtest21, 21 },
  { "argtest22",  (DL_FUNC) argtest22, 22 },
  { "argtest23",  (DL_FUNC) argtest23, 23 },
  { "argtest24",  (DL_FUNC) argtest24, 24 },
  { "argtest25",  (DL_FUNC) argtest25, 25 },
  { "argtest26",  (DL_FUNC) argtest26, 26 },
  { "argtest27",  (DL_FUNC) argtest27, 27 },
  { "argtest28",  (DL_FUNC) argtest28, 28 },
  { "argtest29",  (DL_FUNC) argtest29, 29 },
  { "argtest30",  (DL_FUNC) argtest30, 30 },

  { NULL, NULL, 0 }
};

void R_init_safecall(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
  R_RegisterCCallable("safecall", "r_on_exit", (DL_FUNC) r_on_exit_reg);
}
