// Generated by rstantools.  Do not edit by hand.

/*
    stansum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    stansum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with stansum.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_MaltielBEM_count_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_MaltielBEM_count");
    reader.add_event(40, 38, "end", "model_MaltielBEM_count");
    return reader;
}
template <bool propto, typename T0__, typename T1__, typename T2__, typename T3__>
typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
ll_lpdf(const T0__& y,
            const T1__& d,
            const T2__& m,
            const T3__& rho, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        current_statement_begin__ = 3;
        return stan::math::promote_scalar<fun_return_scalar_t__>(((binomial_coefficient_log(d, y) + lbeta(((m * ((1 / rho) - 1)) + y), ((d + ((1 - m) * ((1 / rho) - 1))) - y))) - lbeta((m * ((1 / rho) - 1)), ((1 - m) * ((1 / rho) - 1)))));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
template <typename T0__, typename T1__, typename T2__, typename T3__>
typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
ll_lpdf(const T0__& y,
            const T1__& d,
            const T2__& m,
            const T3__& rho, std::ostream* pstream__) {
    return ll_lpdf<false>(y,d,m,rho, pstream__);
}
struct ll_lpdf_functor__ {
    template <bool propto, typename T0__, typename T1__, typename T2__, typename T3__>
        typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
    operator()(const T0__& y,
            const T1__& d,
            const T2__& m,
            const T3__& rho, std::ostream* pstream__) const {
        return ll_lpdf(y, d, m, rho, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_MaltielBEM_count
  : public stan::model::model_base_crtp<model_MaltielBEM_count> {
private:
        int N;
        int K;
        matrix_d y;
        vector_d m;
        vector_d L;
public:
    model_MaltielBEM_count(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_MaltielBEM_count(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_MaltielBEM_count_namespace::model_MaltielBEM_count";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            current_statement_begin__ = 10;
            validate_non_negative_index("y", "N", N);
            validate_non_negative_index("y", "K", K);
            context__.validate_dims("data initialization", "y", "matrix_d", context__.to_vec(N,K));
            y = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, K);
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_j_2_max__ = K;
            size_t y_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < y_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                    y(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 11;
            validate_non_negative_index("m", "K", K);
            context__.validate_dims("data initialization", "m", "vector_d", context__.to_vec(K));
            m = Eigen::Matrix<double, Eigen::Dynamic, 1>(K);
            vals_r__ = context__.vals_r("m");
            pos__ = 0;
            size_t m_j_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < m_j_1_max__; ++j_1__) {
                m(j_1__) = vals_r__[pos__++];
            }
            check_greater_or_equal(function__, "m", m, 0);
            check_less_or_equal(function__, "m", m, 1);
            current_statement_begin__ = 12;
            validate_non_negative_index("L", "N", N);
            context__.validate_dims("data initialization", "L", "vector_d", context__.to_vec(N));
            L = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
            vals_r__ = context__.vals_r("L");
            pos__ = 0;
            size_t L_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < L_j_1_max__; ++j_1__) {
                L(j_1__) = vals_r__[pos__++];
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 16;
            validate_non_negative_index("d_raw", "N", N);
            num_params_r__ += N;
            current_statement_begin__ = 17;
            num_params_r__ += 1;
            current_statement_begin__ = 18;
            num_params_r__ += 1;
            current_statement_begin__ = 19;
            validate_non_negative_index("rho", "K", K);
            num_params_r__ += K;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_MaltielBEM_count() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 16;
        if (!(context__.contains_r("d_raw")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable d_raw missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("d_raw");
        pos__ = 0U;
        validate_non_negative_index("d_raw", "N", N);
        context__.validate_dims("parameter initialization", "d_raw", "vector_d", context__.to_vec(N));
        Eigen::Matrix<double, Eigen::Dynamic, 1> d_raw(N);
        size_t d_raw_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < d_raw_j_1_max__; ++j_1__) {
            d_raw(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lb_unconstrain(0, d_raw);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable d_raw: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 17;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(3, 8, mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 18;
        if (!(context__.contains_r("sigma")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma", "double", context__.to_vec());
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain((1. / 4), 2, sigma);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 19;
        if (!(context__.contains_r("rho")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable rho missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("rho");
        pos__ = 0U;
        validate_non_negative_index("rho", "K", K);
        context__.validate_dims("parameter initialization", "rho", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> rho(K);
        size_t rho_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            rho(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lub_unconstrain(0, 1, rho);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable rho: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 16;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> d_raw;
            (void) d_raw;  // dummy to suppress unused var warning
            if (jacobian__)
                d_raw = in__.vector_lb_constrain(0, N, lp__);
            else
                d_raw = in__.vector_lb_constrain(0, N);
            current_statement_begin__ = 17;
            local_scalar_t__ mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.scalar_lub_constrain(3, 8, lp__);
            else
                mu = in__.scalar_lub_constrain(3, 8);
            current_statement_begin__ = 18;
            local_scalar_t__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lub_constrain((1. / 4), 2, lp__);
            else
                sigma = in__.scalar_lub_constrain((1. / 4), 2);
            current_statement_begin__ = 19;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> rho;
            (void) rho;  // dummy to suppress unused var warning
            if (jacobian__)
                rho = in__.vector_lub_constrain(0, 1, K, lp__);
            else
                rho = in__.vector_lub_constrain(0, 1, K);
            // transformed parameters
            current_statement_begin__ = 23;
            validate_non_negative_index("d", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> d(N);
            stan::math::initialize(d, DUMMY_VAR__);
            stan::math::fill(d, DUMMY_VAR__);
            stan::math::assign(d,add(L, d_raw));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 23;
            size_t d_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < d_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(d(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: d" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable d: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 27;
            lp_accum__.add(lognormal_log<propto__>(d, mu, sigma));
            current_statement_begin__ = 28;
            lp_accum__.add(uniform_log<propto__>(mu, 3, 8));
            current_statement_begin__ = 29;
            lp_accum__.add(uniform_log<propto__>(sigma, (1. / 4), 2));
            current_statement_begin__ = 30;
            lp_accum__.add(uniform_log<propto__>(rho, 0, 1));
            current_statement_begin__ = 31;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 32;
                for (int k = 1; k <= K; ++k) {
                    current_statement_begin__ = 33;
                    if (as_bool(logical_gte(get_base1(y, i, k, "y", 1), 0))) {
                        current_statement_begin__ = 34;
                        lp_accum__.add(ll_lpdf<propto__>(get_base1(y, i, k, "y", 1), get_base1(d, i, "d", 1), get_base1(m, k, "m", 1), get_base1(rho, k, "rho", 1), pstream__));
                    }
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("d_raw");
        names__.push_back("mu");
        names__.push_back("sigma");
        names__.push_back("rho");
        names__.push_back("d");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_MaltielBEM_count_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> d_raw = in__.vector_lb_constrain(0, N);
        size_t d_raw_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < d_raw_j_1_max__; ++j_1__) {
            vars__.push_back(d_raw(j_1__));
        }
        double mu = in__.scalar_lub_constrain(3, 8);
        vars__.push_back(mu);
        double sigma = in__.scalar_lub_constrain((1. / 4), 2);
        vars__.push_back(sigma);
        Eigen::Matrix<double, Eigen::Dynamic, 1> rho = in__.vector_lub_constrain(0, 1, K);
        size_t rho_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            vars__.push_back(rho(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 23;
            validate_non_negative_index("d", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> d(N);
            stan::math::initialize(d, DUMMY_VAR__);
            stan::math::fill(d, DUMMY_VAR__);
            stan::math::assign(d,add(L, d_raw));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t d_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < d_j_1_max__; ++j_1__) {
                    vars__.push_back(d(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_MaltielBEM_count";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t d_raw_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < d_raw_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "d_raw" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        size_t rho_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rho" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t d_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < d_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "d" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t d_raw_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < d_raw_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "d_raw" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        size_t rho_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rho" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t d_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < d_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "d" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_MaltielBEM_count_namespace::model_MaltielBEM_count stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
