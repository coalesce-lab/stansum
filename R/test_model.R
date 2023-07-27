#' Test model
#'
#' A test Bernoulli model from Stan documentation.
#'
#' @format An object of R6 class `CmdStanModel`.
#'
#' @section Data:
#'
#' ```{r model-data, echo = FALSE, results="asis"}
#' cat(md_itemize(format_data(test_model)))
#' ```
#'
#' where
#'
#' - `N`: Number of trials
#' - `y`: Vector of 0s and 1s
#'
#' @section Parameters:
#'
#' ```{r model-parameters, echo = FALSE, results="asis"}
#' cat(md_itemize(format_parameters(test_model)))
#' ```
#'
#' where
#'
#' - `theta`: Probability
#'
#'
#' @export

test_model <- {
  p <- system.file("stan", "bernoulli.stan", package = "stansum")
  stan_package_model2(p)
}