# Knit the .orig source into the static vignette committed to the repository.
# Needs the package installed with compiled models and CmdStan available;
# R CMD build then only renders the markdown and never samples anything.
# Run from the package root: source("vignettes/precompile.R")
knitr::knit("vignettes/stansum.Rmd.orig", output = "vignettes/stansum.Rmd")
