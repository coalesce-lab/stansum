# Do a test run of a function call
#
# A test run of a function call calls a function with externally defined values
# of (some of) the arguments.
#
# @param cl function call
# @param ... other arguments, currently ignored
#
# @details A test run of a call, say, `foobar(a=1)` might be set up by defining
#   a function `test_run_foo()` which modifies arguments of a call to the
#   testing values. The modified call is evaluated and the value returned.

test_run <- function(cl, ...) {
  e <- rlang::enexpr(cl)
  mod_fun_name <- paste0("test_run_", as.character(e[[1]]))
  mod_fun <- get(mod_fun_name)
  e2 <- mod_fun(rlang::call_standardise(e))
  eval(e2)
}

test_run_mean <- function(e) {
  rlang::call_modify(e, na.rm=TRUE)
}


if(FALSE) {
  mean(c(1, 2, NA))

  r <- test_run(
    mean(c(1, 2, NA))
  )

  rlang::call_modify()
}
