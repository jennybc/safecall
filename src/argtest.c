
#include <R.h>
#include <Rinternals.h>

SEXP argtest0() {
  return ScalarInteger(0);
}

SEXP argtest1(SEXP a1) {
  return ScalarInteger(INTEGER(a1)[0]);
}

SEXP argtest2(SEXP a1, SEXP a2) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0]);
}

SEXP argtest3(SEXP a1, SEXP a2, SEXP a3) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0]);
}

SEXP argtest4(SEXP a1, SEXP a2, SEXP a3, SEXP a4) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0]);
}

SEXP argtest5(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0]);
}

SEXP argtest6(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5, SEXP a6) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0]);
}

SEXP argtest7(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5, SEXP a6,
	      SEXP a7) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0]);
}

SEXP argtest8(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5, SEXP a6,
	      SEXP a7, SEXP a8) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0] + INTEGER(a8)[0]);
}

SEXP argtest9(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5, SEXP a6,
	      SEXP a7, SEXP a8, SEXP a9) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0] + INTEGER(a8)[0] + INTEGER(a9)[0]);
}

SEXP argtest10(SEXP a1, SEXP a2, SEXP a3, SEXP a4, SEXP a5, SEXP a6,
	       SEXP a7, SEXP a8, SEXP a9, SEXP a10) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0] + INTEGER(a8)[0] + INTEGER(a9)[0] +
		       INTEGER(a10)[0]);
}

SEXP argtest11(SEXP a1, SEXP a2, SEXP a3, SEXP a4 , SEXP a5 , SEXP a6,
	       SEXP a7, SEXP a8, SEXP a9, SEXP a10, SEXP a11) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0] + INTEGER(a8)[0] + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0]);
}

SEXP argtest12(SEXP a1, SEXP a2, SEXP a3, SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7, SEXP a8, SEXP a9, SEXP a10, SEXP a11, SEXP a12) {
  return ScalarInteger(INTEGER(a1)[0] + INTEGER(a2)[0] + INTEGER(a3)[0] +
		       INTEGER(a4)[0] + INTEGER(a5)[0] + INTEGER(a6)[0] +
		       INTEGER(a7)[0] + INTEGER(a8)[0] + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0]);
}

SEXP argtest13(SEXP a1 , SEXP a2, SEXP a3, SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8, SEXP a9, SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0]);
}

SEXP argtest14(SEXP a1 , SEXP a2, SEXP a3, SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8, SEXP a9, SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0]);
}

SEXP argtest15(SEXP a1 , SEXP a2 , SEXP a3, SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9, SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0]);
}

SEXP argtest16(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0]);
}

SEXP argtest17(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0]);
}

SEXP argtest18(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0]);
}

SEXP argtest19(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0]);
}

SEXP argtest20(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0]);
}

SEXP argtest21(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0]);
}

SEXP argtest22(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0]);
}

SEXP argtest23(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0]);
}

SEXP argtest24(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0]);
}

SEXP argtest25(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0]);
}

SEXP argtest26(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25, SEXP a26) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0] + INTEGER(a26)[0]);
}

SEXP argtest27(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25, SEXP a26, SEXP a27) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0] + INTEGER(a26)[0] + INTEGER(a27)[0]);
}

SEXP argtest28(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25, SEXP a26, SEXP a27, SEXP a28) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0] + INTEGER(a26)[0] + INTEGER(a27)[0] +
		       INTEGER(a28)[0]);
}

SEXP argtest29(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25, SEXP a26, SEXP a27, SEXP a28, SEXP a29) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0] + INTEGER(a26)[0] + INTEGER(a27)[0] +
		       INTEGER(a28)[0] + INTEGER(a29)[0]);
}

SEXP argtest30(SEXP a1 , SEXP a2 , SEXP a3 , SEXP a4 , SEXP a5 , SEXP a6 ,
	       SEXP a7 , SEXP a8 , SEXP a9 , SEXP a10, SEXP a11, SEXP a12,
	       SEXP a13, SEXP a14, SEXP a15, SEXP a16, SEXP a17, SEXP a18,
	       SEXP a19, SEXP a20, SEXP a21, SEXP a22, SEXP a23, SEXP a24,
	       SEXP a25, SEXP a26, SEXP a27, SEXP a28, SEXP a29, SEXP a30) {
  return ScalarInteger(INTEGER(a1)[0]  + INTEGER(a2)[0]  + INTEGER(a3)[0] +
		       INTEGER(a4)[0]  + INTEGER(a5)[0]  + INTEGER(a6)[0] +
		       INTEGER(a7)[0]  + INTEGER(a8)[0]  + INTEGER(a9)[0] +
		       INTEGER(a10)[0] + INTEGER(a11)[0] + INTEGER(a12)[0] +
		       INTEGER(a13)[0] + INTEGER(a14)[0] + INTEGER(a15)[0] +
		       INTEGER(a16)[0] + INTEGER(a17)[0] + INTEGER(a18)[0] +
		       INTEGER(a19)[0] + INTEGER(a20)[0] + INTEGER(a21)[0] +
		       INTEGER(a22)[0] + INTEGER(a23)[0] + INTEGER(a24)[0] +
		       INTEGER(a25)[0] + INTEGER(a26)[0] + INTEGER(a27)[0] +
		       INTEGER(a28)[0] + INTEGER(a29)[0] + INTEGER(a30)[0]);
}
