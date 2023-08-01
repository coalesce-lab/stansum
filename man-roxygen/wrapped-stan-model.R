#'
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @details Calling this function will load the model object using [get_model()]
#'   and sample from the posterior using the [cmdstanr::sample()] method.
#'
#'   See Laga et al (2021) for a review of other models for Aggregated
#'   Relational Data (ARD).
#'
#' @returns Object of class [cmdstanr::CmdStanMCMC] containing the samples.
#'
#' @seealso Use [get_model()] to return Stan model object of class
#'   [cmdstanr::CmdStanModel] without fitting it.
#'
#' @family Models for ARD
#'
#' @references Laga, I., Bao, L., & Niu, X. (2021). Thirty Years of The Network
#'   Scale-up Method. *Journal of the American Statistical Association*,
#'   116(535), 1548–1559.
#'
