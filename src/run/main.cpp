#include <iostream>

#include "genetic_algorithm/genetic_algorithm.h"
#include "genetic_algorithm/genes.h"

namespace gaus{

void
run_gaus(){

  const int target = 43;

  const std::function<double(arma::uvec)> fitness_function =
    [&target](const arma::uvec &genes){

        const arma::uvec powers_of_two = {1, 2, 4, 8, 16, 32};

        const int strength = arma::accu(powers_of_two % genes);

        return std::abs(strength - target);
  };

  const auto solution =
      genetic_algorithm::find_solution(fitness_function, 6, 6, 0.7);

  solution.print("solution");
}

}

int main(){

gaus::run_gaus();

return 0;

}
