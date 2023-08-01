#' List or get Stan model objects
#'
#' List Stan models available in this package or load them in the form of
#' `CmdStanModel` objects as implemented in the \pkg{cmdstanr} package.
#'
#' @param name character; name of the model to load
#' @param ... arguments passed to [instantiate::stan_package_model]
#'
#' @returns `get_model` returns an "CmdStanModel" object.
#'
#' @export
get_model <- function(name, ...) {
  stopifnot(name %in% list_models())
  instantiate::stan_package_model(name = name, package = "stansum", ...)
}


#' @rdname get_model
#'
#' @return `list_models` returns a character vector of model names provided
#'   with the package.
#'
#' @export
list_models <- function() {
  gsub(
    "\\.stan$",
    "",
    list.files(
      path = system.file("stan", package = "stansum"),
      pattern = "\\.stan$"
    )
  )
}
