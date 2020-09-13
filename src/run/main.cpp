#include <iostream>
#include <chrono>

#include "underground_modelling/underground_modelling.h"

#include "genetic_algorithm/genetic_algorithm.h"

namespace gaus {

struct InputParam {

  int colony_size = 20;
  int gene_length = 6;
  double selection_rate = 0.7;
  double mutation_rate = 0.2;

};

void
run_gaus() {

  const InputParam input_param;

  const auto model = underground_modelling::Model();

  const auto start_time = std::chrono::steady_clock::now();

  const auto end_time = std::chrono::steady_clock::now();

  const auto solution =
      genetic_algorithm::find_solution(model.fitness_function,
                                       input_param.colony_size,
                                       input_param.gene_length,
                                       input_param.selection_rate,
                                       input_param.mutation_rate
  );


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
