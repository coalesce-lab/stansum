#'
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @details Calling this function(s) will load the model object using
#'   [get_model()] and sample from the posterior using the [cmdstanr::sample()]
#'   method.
#'
#' @returns Object of class [cmdstanr::CmdStanMCMC] containing the samples.
#'
#' @seealso Use [get_model()] to return Stan model object of class
#'   [cmdstanr::CmdStanModel] without fitting it.
#'
#' @family models in this package
#'
