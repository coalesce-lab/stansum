# Utilities for reporting properties of Stan model objects.



# Format data -------------------------------------------------------------

format_data <- function(object, ...) UseMethod("format_data")

#' @export
format_data.CmdStanModel <- function(object, ...) {
  d <- object$variables()$data
  vapply(
    seq_along(d),
    function(i) {
      paste0(names(d)[i], " < ", d[[i]]$type, " > \\[", d[[i]]$dimensions, "\\]")
    },
    character(1)
  )
}



# Format model parameters -------------------------------------------------

format_parameters <- function(object, ...) UseMethod("format_parameters")

#' @export
format_parameters.CmdStanModel <- function(object, ...) {
  d <- object$variables()$parameters
  vapply(
    seq_along(d),
    function(i) {
      paste0(names(d)[i], " < ", d[[i]]$type, " > \\[", d[[i]]$dimensions, "\\]")
    },
    character(1)
  )
}




# Generating Markdown -----------------------------------------------------

md_itemize <- function(x) {
  paste0("- ", x, "\n")
}
