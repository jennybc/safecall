
#define DEFINE_ON_EXIT						\
  void on_exit(void (*func)(void*), void *data) {		\
    static void (*fun)(void (*func)(void*), void *data) = NULL;	\
    if (fun == NULL)						\
      fun = (void (*)(void (*)(void *), void *))		\
	R_GetCCallable("safecall", "on_exit");			\
    fun(func, data);						\
  }
