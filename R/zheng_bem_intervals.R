#' BEM of Zheng etal for ordered categorical intervals responses
#'
#' @description Variation on the BEM of Zheng et al for categorical response.
#'
#' @template wrapped-stan-model
#'
#' @param N integer; number of respondents
#' @param K integer; number of subpopulations
#' @param J integer; number of response categories
#' @param y_cat matrix; ARD of integer responses 1..
#' @param L,U numeric; vector of lower and upper bounds of the intervals
#' @param ... other arguments passed to [cmdstanr::sample()]
#'


zheng_bem_intervals <- function(
    N,
    K,
    J,
    y_cat,
    L,
    U,
    ...
    ) {
  mod <- get_model("ZhengBEM_intervals")
  d <- list(N=N, K=K, J=J, y_cat = y_cat, L=L, U=U)
  mod$sample(data = d, ...)
}
