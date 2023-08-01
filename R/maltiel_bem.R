#' Maltiel et al (2015) Barrier Effects Model
#'
#' @name maltiel_bem
#'
#' @references Baum, D. S., & Marsden, P. V. (2023). Uses and limitations of
#'   dichotomous aggregate relational data. *Social Networks*, 74, 42–61.
#'   <https://doi.org/10.1016/j.socnet.2023.02.001>
#'
#' Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A. J.
#'   (2015). Estimating Population Size Using the Network Scale Up Method. *The
#'   Annals of Applied Statistics*, 9(3), 1247–1277.
#'   <https://doi.org/10.1214/15-AOAS827>
#'
#' @importFrom instantiate stan_package_model
#'
#' @family Models of Maltiel et al (2015)




#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_count` -- model for count responses
#'
#' @param N integer; population size
#' @param K integer; number of sub-populations
#' @param y integer matrix; ARD
#' @param m numeric; vector of fractional sizes of sub-populations
#' @param L numeric; lower bound on degree
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @export
maltiel_bem_count <- function(N, K, y, m, L, ...) {
  mod <- get_model("MaltielBEM_count")
  d <- list(N=N, K=K, y=y, m=m, L=L)
  mod$sample(data = d, ...)
}


#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_dichotomous` -- model for dichotmous responses
#'   proposed by Baum & Marsden (2023).
#' @export
maltiel_bem_dichotomous <- function(N, K, y, m, L, ...) {
  mod <- get_model("MaltielBEM_dichotomous")
  d <- list(N=N, K=K, y=y, m=m, L=L)
  mod$sample(data = d, ...)
}


#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_trichotomous` -- model for trichotomous responses
#'   proposed by Baum & Marsden (2023).
#' @format NULL
#' @export
maltiel_bem_trichotomous <- function(N, K, y, m, L, ...) {
  mod <- get_model("MaltielBEM_trichotomous")
  d <- list(N=N, K=K, y=y, m=m, L=L)
  mod$sample(data = d, ...)
}
