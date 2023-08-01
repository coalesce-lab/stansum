#' Test model
#'
#' A test Bernoulli model from Stan documentation.
#'
#' @format An object of R6 class `CmdStanModel`.
#'
#' @section Data:
#'
#' where
#'
#' - `N`: Number of trials
#' - `y`: Vector of 0s and 1s
#'
#' @section Parameters:
#'
#'
#' where
#'
#' - `theta`: Probability
#'
#'
#' @importFrom instantiate stan_package_model
#' @export

test_model <- {
  p <- system.file("stan", "bernoulli.stan", package = "stansum")
}
