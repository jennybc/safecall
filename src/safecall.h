
#include <R.h>
#include <Rinternals.h>

#define SAFECALL_REGISTRATION_RECORD \
  { "c_safecall", (DL_FUNC) c_safecall, 3 }
#define r_on_exit(a,b) r_on_exit_reg(a,b)

SEXP c_safecall(SEXP addr, SEXP numpar, SEXP args);
void r_on_exit_reg(void (*func)(void*), void *data);
