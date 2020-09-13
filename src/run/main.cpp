#include <iostream>
#include <chrono>

#include "genetic_algorithm/genetic_algorithm.h"
#include "genetic_algorithm/genes.h"

namespace gaus {

void
run_gaus() {

  const auto start_time = std::chrono::steady_clock::now();

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
