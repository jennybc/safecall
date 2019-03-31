
# safecall

> Correct Resource Cleaup in C Code

[![Linux Build Status](https://travis-ci.org/gaborcsardi/safecall.svg?branch=master)](https://travis-ci.org/gaborcsardi/safecall)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/github/gaborcsardi/safecall?svg=true)](https://ci.appveyor.com/project/gaborcsardi/safecall)
[![](http://www.r-pkg.org/badges/version/safecall)](http://www.r-pkg.org/pkg/safecall)
[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/safecall)](http://www.r-pkg.org/pkg/safecall)

Correct Resource Cleaup in C Code

## Features

* Add exit handlers to a foreign `.Call()` to C, by simply calling a
  function, and replacing `.Call()` with `safecall()`.
* Exit handlers are executed both for normal exit, and on error as well.
* Exit handlers are executed in reverse order. Last added runs first.
* `safecall()`s can be nested. I.e. the C code can call back to R, and then
  back to C again via `safecall()` or `.Call()`.
* Exit handlers can be added from any function, they don't need to be called
  directly from the function called from `safecall()`.

## Limitations

* You can have at most 100 exit handlers for a `safecall()`. Definining
more than that will throw an error. If you need more exit handlers, you
can create a `struct` for storing multiple resources, and then have a single
exit handler for the whole struct.

* You can pass at most 30 arguments to `safecall()` currently. If you need
more, you can put them in a list.

## Usage

There are two ways to use safecall in your package. The first way involves
linking your package to safecall. This makes safecall a dependency of
your package.

The second way is to simply copy over some C and R files from safecall
to your package. This has the advantage of avoiding a dependency, and the
disadvantage of not getting safecall updates automatically.

### Linking to safecall

You need to do the following steps:

1. Make sure your package uses native routine registration and `.Call()`
   to call back to C. (safecall does not currently work with `.C()` and
   `.External()`.
2. Specify the safecall package in both the `LinkingTo` and `Imports`
   field of the `DESCRIPTION` of your package.
3. Use `safecall()` instead of [base::.Call()], with a `CallRoutine`
   object a a first argument. (I.e. the name of the C function you want
   to call, without quotes.)
4. In your C file include the `safecall.h` header. (The include path
   will be set up by R automatically if you used `LinkingTo` above.)
5. "Call" the `DEFINE_ON_EXIT` macro in your code file. This will define
   the `on_exit()` C function that you can call from your code to add
   exit handlers.

### Copying over safecall files

1. Make sure your package uses native routine registration and `.Call()`
   to call back to C. (safecall does not currently work with `.C()` and
   `.External()`.
2. Copy over the `src/safecall.c` and `src/safecall.h` C files and the
   `safecall.R` R file from the safecall package to your package.
3. Make sure you register the `c_safecall()` function, you can do that via
   the `SAFECALL_RESGISTRATION_RECORD` macro:

   ```c
   #include "safecall.h"
   static const R_CallMethodDef callMethods[]  = {
     { "myfun1",     (DL_FUNC) myfun1,  2 },
     ...
     SAFECALL_REGISTRATION_RECORD,
     { NULL, NULL, 0 }
   };
   ``` 

### Example

Now you can call `on_exit()` to create exit handlers. It has two arguments,
the first one the exit handler function, that takes a `void*` pointer.
The second one is the exit data, `void*`, which will be passed to the exit
handler handler funcion on cleanup.

Note that the exit handlers are always called, i.e. both is case of
normal and non-normal termination. They are always called in reverse
order.

Here is an example on how to use safecall in C:

```c
#include <safecall.h>

DEFINE_ON_EXIT

void cleanup_free(void *data) {
  free(data);
}

void cleanup_close(void *data) {
  int fd = *(int*)(data);
  close(fd);
}

SEXP myfun(SEXP fn) {
  const char *cfn = CHAR(STRING_ELT(fn, 0));

  char *x = malloc(100);
  on_exit(cleanup_free, x);

  int *fd = malloc(1);
  on_exit(cleanup_free, fd);

  *fd = open(cfn, O_WRONLY | O_CREAT);
  if (*fd == -1) error("Cannot open file `%s`", cfn);
  on_exit(cleanup_close, fd);

  return ScalarInteger(42);
}
```

You can register `myfun()` as usual, and call it from R with `safecall()`:
```r
safecall(myfun, tempfile())
```

One important part in the example above is that we need to dynamically
allocate the integer holding the file descriptor for the open file.
It is important to point out that the simplified solution:

```c
int fd = open(cfn, O_WRONLY | O_CREAT);
on_exit(cleanup_close, &fd);
```

(and the corresponding modification of `cleanup_close()`) will not work,
because we store a pointer to a local stack variable (`fd`), and by the
time the cleanup function runs, this function is not on the stack, so the
pointer will point to another function's stack, or to garbage, resulting
undefined behavior. Interestingly, this incorrect method often works in
practice, depending luck and the platform. However, it is still
non-deterministic on all platforms and must be avoided.

## License

MIT © [Gábor Csárdi](https://github.com/gaborcsardi)
