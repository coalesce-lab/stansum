#' A simple Bernoulli model for testing purposes
#'
#' A test Bernoulli model taken from Stan documentation.
#'
#' @param N integer; number of trials
#' @param y integer; vector of Bernoulli outcomes
#'
#' @template wrapped-stan-model
#'
#' @export

test_model <- function(N, y, ...) {
  mod <- get_model("bernoulli")
  mod$sample(data = list(N=N, y=y), ...)
}
