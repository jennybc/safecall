
#include <R_ext/Rdynload.h>

#define DEFINE_R_ON_EXIT					\
  void r_on_exit(void (*func)(void*), void *data) {		\
    static void (*fun)(void (*func)(void*), void *data) = NULL;	\
    if (fun == NULL)						\
      fun = (void (*)(void (*)(void *), void *))		\
	R_GetCCallable("safecall", "r_on_exit");		\
    fun(func, data);						\
  }
