
#include <R.h>
#include <Rinternals.h>

#define SAFECALL_REGISTRATION_RECORD \
  { "c_safecall", (DL_FUNC) c_safecall, 3 }

SEXP c_safecall(SEXP addr, SEXP numpar, SEXP args);
void on_exit_reg(void (*func)(void*), void *data);
