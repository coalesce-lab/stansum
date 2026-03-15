#' BEM of Zheng etal for ordered categorical intervals response
#'
#' Variation on the BEM of Zheng et al for categorical response. The response
#' categories correspond to grouped counts.
#'
#' @template wrapped-stan-model
#'
#' @param y_cat matrix; ARD of integer responses 1..
#' @param J integer; number of response categories
#' @param L,U numeric; vector of lower and upper bounds of the intervals
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @details Matrix `y_cat` is assumed to contain integers 1..J. Each value
#'   corresponds to an interval bounds of which are defined by the corresponding
#'   elements of arguments `L` and `U`. In other words, for example, `y_cat=2`
#'   corresponds to counts in the interval defined by `L[2]` and `U[2]`.
#'
#' @references Zheng, T., Salganik, M. J., & Gelman, A. (2006). How Many People
#'   Do You Know in Prison? Using Overdispersion in Count Data to Estimate
#'   Social Structure in Networks. Journal of the American Statistical
#'   Association, 101(474), 409–423. \doi{10.1198/016214505000001168}
#'
#' @family models of Zheng et al (2006)
#'
#' @export
#'
#' @examples
#' \dontrun{
#' set.seed(666)
#' alphas <- log(c(2,2,3,3))
#' betas <- c(1, 2, 3)
#' omega <- rep(1, length(betas))
#' mu <- outer(alphas, betas, "+") |>
#'   exp() |>
#'   sweep(2, omega, "*")
#' omegas <- omega[col(mu)]
#' dim(omegas) <- dim(mu)
#' y <- rnbinom(length(mu), mu = mu, size = omegas)
#' dim(y) <- dim(mu)
#' y
#'
#' ycat <- cut(y, c(-Inf, 10, 20, 50, Inf)) |>
#'   as.numeric() |>
#'   structure(dim = dim(y))
#'
#'
#' fit <- zheng_bem_intervals(
#'   y_cat = ycat,
#'   J = 4,
#'   L = c(0, 11, 21, 51),
#'   U = c(10, 20, 50, -1),
#'   iter_warmup = 500,
#'   iter_sampling = 250,
#'   chains = 4,
#'   parallel_chains = 4,
#'   threads_per_chain = 2
#' )
#'
#' fit$diagnostic_summary()
#'
#' # Trace rank plot
#' fit$draws("alpha") |>
#'   apply(3, median)
#' }


zheng_bem_intervals <- function(
    y_cat,
    J,
    L,
    U,
    ...
    ) {
  N <- nrow(y_cat)
  K <- ncol(y_cat)
  mod <- get_model("ZhengBEM_intervals")
  d <- list(N=N, K=K, J=J, y_cat = y_cat, L=L, U=U)
  mod$sample(data = d, ...)
}
