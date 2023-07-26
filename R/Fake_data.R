#' Datasets generated from ARD models
#'
#' Some artificial datasets simulated from various ARD models.
#'
#' @name Fake
#' @docType data
#' @keywords data
#' @format Unless stated otherwise below all datasets are data frames with
#'   respondents in rows and subpopulations in columns.
#'


#' @rdname Fake
#'
#' @details - `Fake_maltiel_RD` is sampled from Maltiel et al (2015) Random
#'   Degree model assuming `r nrow(Fake_maltiel_RD)` respondents and
#'   `r ncol(Fake_maltiel_RD)` subpopulations.
#'
#' @references Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A. J.
#'   (2015). Estimating Population Size Using the Network Scale Up Method. The
#'   Annals of Applied Statistics, 9(3), 1247–1277.
#'   <https://doi.org/10.1214/15-AOAS827>

"Fake_maltiel_RD"
