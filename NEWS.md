# stansum 1.0.1


# stansum 1.0.0

* First release.

* `list_models()` and `get_model()` give access to the Stan models bundled with
  the package (precompiled at install time via **instantiate**, sampled with
  **cmdstanr**).

* Wrapper functions for fitting the models to Aggregated Relational Data:

  - Zheng et al (2006): `zheng_gp_count()`, `zheng_gp_dichotomous()`,
    `zheng_bem_count()`, `zheng_bem_count2()`, `zheng_bem_dichotomous()`,
    `zheng_bem_trichotomous()`.
  - Maltiel et al (2015): `maltiel_bem_count()`, `maltiel_bem_dichotomous()`,
    `maltiel_bem_trichotomous()`, `maltiel_rdm_count()`,
    `maltiel_rd_dichotomous()`, `maltiel_tbm_count()`, `maltiel_cm_count()`.

* Example data `Fake_maltiel_RD` and an introductory vignette.
