
#' Call a native function with correct resource cleanup
#'
#' @param cfun A [base::RegisteredNativeSymbol] object.
#' @param ... Arguments to pass to `cfun`.
#'
#' This function is similar to [base::.Call()], but allows proper
#' resource cleanup, via exit handlers.
#'
#' To call a native function, you must use native routine registration
#' in your package. See [getDLLRegisteredRoutines]. Then you need to
#' do the following simple steps:
#' 1. Use `safecall()` instead of [base::.Call()], with a `CallRoutine`
#'    object a a first argument.
#' 2. Specify the safecall package in both the `LinkingTo` and `Imports`
#'    field of the `DESCRIPTION` of your package.
#' 3. In your C file include the `safecall.h` header. (The include path
#'    will be set up by R automatically if you used `LinkingTo` above.)
#' 4. "Call" the `DEFINE_ON_EXIT` macro in your code file. This will define
#'    the `on_exit()` C function that you can call from your code to add
#'    exit handlers.
#' 5. Call `on_exit()` to create exit handlers. It has two arguments, the
#'    first one the exit handler function, that takes a `void*` pointer.
#'    The second one is the exit data, `void*`, which will be passed to
#'    the exit handler handler funcion on cleanup.
#'
#' Note that the exit handlers are always called, i.e. both is case of
#' normal and non-normal termination. They are always called in reverse
#' order.
#'
#' @useDynLib safecall,.registration = TRUE
#' @export

safecall <- function(cfun, ...) {
  if (!inherits(cfun, "CallRoutine") ||
      !inherits(cfun$address, "RegisteredNativeSymbol")) {
    stop("Not a .Call routine")
  }
  .Call(c_safecall, cfun$address, cfun$numParameters, list(...))
}
