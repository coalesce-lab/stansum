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
namespace model_ZhengBEM_count_namespace {
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
    reader.add_event(0, 0, "start", "model_ZhengBEM_count");
    reader.add_event(32, 30, "end", "model_ZhengBEM_count");
    return reader;
}
#include <stan_meta_header.hpp>
class model_ZhengBEM_count
  : public stan::model::model_base_crtp<model_ZhengBEM_count> {
private:
        int N;
        int K;
        std::vector<std::vector<int> > y;
public:
    model_ZhengBEM_count(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_ZhengBEM_count(stan::io::var_context& context__,
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
        static const char* function__ = "model_ZhengBEM_count_namespace::model_ZhengBEM_count";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            current_statement_begin__ = 4;
            validate_non_negative_index("y", "N", N);
            validate_non_negative_index("y", "K", K);
            context__.validate_dims("data initialization", "y", "int", context__.to_vec(N,K));
            y = std::vector<std::vector<int> >(N, std::vector<int>(K, int(0)));
            vals_i__ = context__.vals_i("y");
            pos__ = 0;
            size_t y_k_0_max__ = N;
            size_t y_k_1_max__ = K;
            for (size_t k_1__ = 0; k_1__ < y_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                    y[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 8;
            validate_non_negative_index("alpha", "N", N);
            num_params_r__ += N;
            current_statement_begin__ = 9;
            validate_non_negative_index("beta", "K", K);
            num_params_r__ += K;
            current_statement_begin__ = 10;
            validate_non_negative_index("inv_omega", "K", K);
            num_params_r__ += K;
            current_statement_begin__ = 11;
            num_params_r__ += 1;
            current_statement_begin__ = 12;
            num_params_r__ += 1;
            current_statement_begin__ = 13;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_ZhengBEM_count() { }
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
        current_statement_begin__ = 8;
        if (!(context__.contains_r("alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        validate_non_negative_index("alpha", "N", N);
        context__.validate_dims("parameter initialization", "alpha", "vector_d", context__.to_vec(N));
        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha(N);
        size_t alpha_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            alpha(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 9;
        if (!(context__.contains_r("beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta");
        pos__ = 0U;
        validate_non_negative_index("beta", "K", K);
        context__.validate_dims("parameter initialization", "beta", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta(K);
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 10;
        if (!(context__.contains_r("inv_omega")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable inv_omega missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("inv_omega");
        pos__ = 0U;
        validate_non_negative_index("inv_omega", "K", K);
        context__.validate_dims("parameter initialization", "inv_omega", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> inv_omega(K);
        size_t inv_omega_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < inv_omega_j_1_max__; ++j_1__) {
            inv_omega(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lub_unconstrain(0, 1, inv_omega);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable inv_omega: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 11;
        if (!(context__.contains_r("mu_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu_beta");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu_beta", "double", context__.to_vec());
        double mu_beta(0);
        mu_beta = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 12;
        if (!(context__.contains_r("sigma_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_beta");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_beta", "double", context__.to_vec());
        double sigma_beta(0);
        sigma_beta = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 13;
        if (!(context__.contains_r("sigma_alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_alpha");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_alpha", "double", context__.to_vec());
        double sigma_alpha(0);
        sigma_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_alpha: ") + e.what()), current_statement_begin__, prog_reader__());
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
            current_statement_begin__ = 8;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.vector_constrain(N, lp__);
            else
                alpha = in__.vector_constrain(N);
            current_statement_begin__ = 9;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> beta;
            (void) beta;  // dummy to suppress unused var warning
            if (jacobian__)
                beta = in__.vector_constrain(K, lp__);
            else
                beta = in__.vector_constrain(K);
            current_statement_begin__ = 10;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> inv_omega;
            (void) inv_omega;  // dummy to suppress unused var warning
            if (jacobian__)
                inv_omega = in__.vector_lub_constrain(0, 1, K, lp__);
            else
                inv_omega = in__.vector_lub_constrain(0, 1, K);
            current_statement_begin__ = 11;
            local_scalar_t__ mu_beta;
            (void) mu_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_beta = in__.scalar_constrain(lp__);
            else
                mu_beta = in__.scalar_constrain();
            current_statement_begin__ = 12;
            local_scalar_t__ sigma_beta;
            (void) sigma_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_beta = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_beta = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 13;
            local_scalar_t__ sigma_alpha;
            (void) sigma_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_alpha = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_alpha = in__.scalar_lb_constrain(0);
            // model body
            current_statement_begin__ = 17;
            lp_accum__.add(normal_log<propto__>(alpha, 0, sigma_alpha));
            current_statement_begin__ = 18;
            lp_accum__.add(normal_log<propto__>(beta, mu_beta, sigma_beta));
            current_statement_begin__ = 19;
            for (int k = 1; k <= K; ++k) {
                {
                current_statement_begin__ = 20;
                local_scalar_t__ omega_k_m1(DUMMY_VAR__);
                (void) omega_k_m1;  // dummy to suppress unused var warning
                stan::math::initialize(omega_k_m1, DUMMY_VAR__);
                stan::math::fill(omega_k_m1, DUMMY_VAR__);
                current_statement_begin__ = 21;
                stan::math::assign(omega_k_m1, inv((inv(get_base1(inv_omega, k, "inv_omega", 1)) - 1)));
                current_statement_begin__ = 22;
                for (int i = 1; i <= N; ++i) {
                    current_statement_begin__ = 23;
                    if (as_bool(logical_gte(get_base1(get_base1(y, i, "y", 1), k, "y", 2), 0))) {
                        {
                        current_statement_begin__ = 24;
                        local_scalar_t__ xi_i_k(DUMMY_VAR__);
                        (void) xi_i_k;  // dummy to suppress unused var warning
                        stan::math::initialize(xi_i_k, DUMMY_VAR__);
                        stan::math::fill(xi_i_k, DUMMY_VAR__);
                        current_statement_begin__ = 25;
                        stan::math::assign(xi_i_k, (omega_k_m1 * stan::math::exp((get_base1(alpha, i, "alpha", 1) + get_base1(beta, k, "beta", 1)))));
                        current_statement_begin__ = 26;
                        lp_accum__.add(neg_binomial_log<propto__>(get_base1(get_base1(y, i, "y", 1), k, "y", 2), xi_i_k, omega_k_m1));
                        }
                    }
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
        names__.push_back("alpha");
        names__.push_back("beta");
        names__.push_back("inv_omega");
        names__.push_back("mu_beta");
        names__.push_back("sigma_beta");
        names__.push_back("sigma_alpha");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
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
        static const char* function__ = "model_ZhengBEM_count_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> alpha = in__.vector_constrain(N);
        size_t alpha_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            vars__.push_back(alpha(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> beta = in__.vector_constrain(K);
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            vars__.push_back(beta(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> inv_omega = in__.vector_lub_constrain(0, 1, K);
        size_t inv_omega_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < inv_omega_j_1_max__; ++j_1__) {
            vars__.push_back(inv_omega(j_1__));
        }
        double mu_beta = in__.scalar_constrain();
        vars__.push_back(mu_beta);
        double sigma_beta = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_beta);
        double sigma_alpha = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_alpha);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
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
        return "model_ZhengBEM_count";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t inv_omega_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < inv_omega_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "inv_omega" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alpha_j_1_max__ = N;
        for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alpha" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t beta_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t inv_omega_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < inv_omega_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "inv_omega" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_ZhengBEM_count_namespace::model_ZhengBEM_count stan_model;
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
