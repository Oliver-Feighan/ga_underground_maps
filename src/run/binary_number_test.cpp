#define BOOST_TEST_MODULE binary_number_test

#include <boost/test/included/unit_test.hpp>

#include "genetic_algorithm/genetic_algorithm.h"

BOOST_AUTO_TEST_CASE(test) {

  using namespace gaus;

  const int target = 27;

  const std::function<double(arma::uvec)> fitness_function =
      [&target](const arma::uvec & genes) {

        const auto powers_of_two = arma::uvec{32, 16, 8, 4, 2, 1};

        const int strength = arma::accu(powers_of_two % genes);

        std::cout << "strength " << strength << std::endl;
        genes.t().print("genes");

        return std::abs(strength - target);
      };

  const auto solution =
      genetic_algorithm::find_solution(fitness_function, 20, 6, 0.8, 0.1);

  const arma::uvec answer = {0, 1, 1, 0, 1, 1};

  BOOST_TEST(arma::approx_equal(solution.genes, answer, "absdiff", 0));

}