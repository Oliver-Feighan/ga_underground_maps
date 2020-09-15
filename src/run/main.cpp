#include <iostream>
#include <chrono>

#include "underground_modelling/underground_modelling.h"

#include "genetic_algorithm/genetic_algorithm.h"

namespace gaus {

struct GAParams {

  int colony_size = 20;
  arma::SizeMat gene_size{60, 60};
  double selection_rate = 0.9;
  double mutation_rate = 0.02;

};

void
run_gaus() {

  const GAParams input_param;

  const underground_modelling::UndergroundModelParams UMParams =
      {{arma::randu(60) * 100,
        arma::randu(60) * 100},
       {0.5, 0.2}};

  const auto model =
      underground_modelling::Model(UMParams.station_coords, UMParams.cost_params);

  const auto start_time = std::chrono::steady_clock::now();

  const auto end_time = std::chrono::steady_clock::now();

  const auto solution =
      genetic_algorithm::find_solution(model.fitness_function,
                                       input_param.colony_size,
                                       input_param.gene_size,
                                       input_param.selection_rate,
                                       input_param.mutation_rate
  );


  const auto time_taken = end_time - start_time;

  const auto symmetrized_solution = arma::symmatu(solution.genes);

  //symmetrized_solution.print("solution");
  std::cout << "found solution in " << solution.n_generations << " generations";

  if (std::chrono::duration_cast<std::chrono::nanoseconds>(time_taken).count() < 1000){
    std::cout << " and " << std::chrono::duration_cast<std::chrono::nanoseconds>(time_taken).count() << " nanoseconds";

  } else if (std::chrono::duration_cast<std::chrono::microseconds>(time_taken).count() < 1000){
    std::cout << " and " << std::chrono::duration_cast<std::chrono::microseconds>(time_taken).count() << " microseconds";

  } else if (std::chrono::duration_cast<std::chrono::milliseconds>(time_taken).count() < 1000){
    std::cout << " and " << std::chrono::duration_cast<std::chrono::milliseconds>(time_taken).count() << " milliseconds";

  } else if (std::chrono::duration_cast<std::chrono::seconds>(time_taken).count() < 1000){
    std::cout << " and " << std::chrono::duration_cast<std::chrono::seconds>(time_taken).count() << " seconds";

  }


}

}

int main() {

  gaus::run_gaus();

  return 0;

}
