#include <iostream>
#include <chrono>

#include "genetic_algorithm/genetic_algorithm.h"
#include "genetic_algorithm/genes.h"

namespace gaus {

void
run_gaus() {

  const auto start_time = std::chrono::steady_clock::now();

  const int target = 43;

  const std::function<double(arma::uvec)> fitness_function =
      [&target](const arma::uvec & genes) {

        const auto powers_of_two = arma::uvec{1, 2, 4, 8, 16, 32};

        const int strength = arma::accu(powers_of_two % genes);

        return std::abs(strength - target);
      };

  const auto solution =
      genetic_algorithm::find_solution(fitness_function, 20, 6, 0.8, 0.1);

  const auto end_time = std::chrono::steady_clock::now();

  const auto time_taken = end_time - start_time;

  solution.genes.t().print("solution");
  std::cout << "found solution in " << solution.n_generations << " generations";
  std::cout << " and " << std::chrono::duration_cast<std::chrono::microseconds>(time_taken).count() << " microseconds";
}

}

int main() {

  gaus::run_gaus();

  return 0;

}
