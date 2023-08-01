#' Zheng et al (2006) Barrier Effects Model
#'
#' @name zheng_bem
#'
#' @description Bayesian model for ARD...
#'
#' @template wrapped-stan-model
#'
#' @references Baum, D. S., & Marsden, P. V. (2023). Uses and limitations of
#'   dichotomous aggregate relational data. *Social Networks*, 74, 42–61.
#'   \doi{10.1016/j.socnet.2023.02.001}
#'
#'   Zheng, T., Salganik, M. J., & Gelman, A. (2006). How Many People Do You
#'   Know in Prison? Using Overdispersion in Count Data to Estimate Social
#'   Structure in Networks. Journal of the American Statistical Association,
#'   101(474), 409–423. \doi{10.1198/016214505000001168}
#'
#' @family models of Zheng et al (2006)




#' @rdname zheng_bem
#'
#' @description - `zheng_bem_count` -- model for count responses
#'
#' @param N integer; population size
#' @param K integer; number of sub-populations
#' @param y integer matrix; ARD
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @export
zheng_bem_count <- function(N, K, y, ...) {
  mod <- get_model("ZhengBEM_count")
  d <- list(N=N, K=K, y=y)
  mod$sample(data = d, ...)
}


#' @rdname zheng_bem
#'
#' @description - `zheng_bem_dichotomous` -- model for dichotmous responses
#'   proposed by Baum & Marsden (2023).
#'
#' @export
zheng_bem_dichotomous <- function(N, K, y, ...) {
  mod <- get_model("ZhengBEM_dichotomous")
  d <- list(N=N, K=K, y=y)
  mod$sample(data = d, ...)
}


#' @rdname zheng_bem
#'
#' @description - `zheng_bem_trichotomous` -- model for trichotomous responses
#'   proposed by Baum & Marsden (2023).
#'
#' @export
zheng_bem_trichotomous <- function(N, K, y, ...) {
  mod <- get_model("ZhengBEM_trichotomous")
  d <- list(N=N, K=K, y=y)
  mod$sample(data = d, ...)
}
