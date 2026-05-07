functions {
  real ll_lpdf(real y, real m, real d) {
    return lchoose(d, y) + y * log(m) + (d - y) * log1m(m);
  }
}

data {
  int N;
  int K;
  matrix[N, K] y;
  vector<lower=0, upper=1>[K] m;
  vector<lower=0>[N] L;
  vector<lower=0>[K] eta;
  vector<lower=0>[K] v;
}

parameters {
  vector<lower=0>[N] d_raw;
  real<lower=3, upper=8> mu;
  real<lower=1./4, upper=2> sigma;
  vector<lower=0, upper=1>[K] tau;
}

transformed parameters {
  vector[N] d = L + d_raw;
}

model {
  d ~ lognormal(mu, sigma);
  mu ~ uniform(3, 8);
  sigma ~ uniform(1./4, 2);
  for (k in 1:K) tau[k] ~ beta(eta[k], v[k]);
  for (i in 1:N) {
    for (k in 1:K) {
      if (y[i, k] >= 0) {
        y[i, k] ~ ll(tau[k] * m[k], d[i]);
      }
    }
  }
}
