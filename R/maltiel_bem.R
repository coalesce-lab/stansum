#' Maltiel et al (2015) Barrier Effects Model
#'
#' @name maltiel_bem
#'
#' @template format-CmdStanModel
#'
#' @references Baum, D. S., & Marsden, P. V. (2023). Uses and limitations of
#'   dichotomous aggregate relational data. Social Networks, 74, 42–61.
#'   <https://doi.org/10.1016/j.socnet.2023.02.001>
#'
#' Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A. J.
#'   (2015). Estimating Population Size Using the Network Scale Up Method. The
#'   Annals of Applied Statistics, 9(3), 1247–1277.
#'   <https://doi.org/10.1214/15-AOAS827>
#'
#' @importFrom instantiate stan_package_model
#'
#' @family Models of Maltiel et al (2015)

#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_count` -- model for count responses
#' @format NULL
#' @export
maltiel_bem_count <- {
  p <- system.file("stan", "MaltielBEM_count.stan", package = "stansum")
}


#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_dichotomous` -- model for dichotmous responses
#'   proposed by Baum & Marsden (2023).
#' @format NULL
#' @export
maltiel_bem_dichotomous <- {
  p <- system.file("stan", "MaltielBEM_dichotomous.stan", package = "stansum")
}


#' @rdname maltiel_bem
#'
#' @description - `maltiel_bem_trichotomous` -- model for trichotomous responses
#'   proposed by Baum & Marsden (2023).
#' @format NULL
#' @export
maltiel_bem_trichotomous <- {
  p <- system.file("stan", "MaltielBEM_trichotomous.stan", package = "stansum")
}
