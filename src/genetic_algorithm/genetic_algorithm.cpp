//
// Created by Oliver Feighan on 8/31/20.
//

#include "genetic_algorithm.h"

#include "genes.h"

namespace gaus::genetic_algorithm {


Solution
find_solution(const std::function<double(arma::umat)> &fitness_function,
                   const int colony_size,
                   const arma::SizeMat gene_size,
                   const double selection_rate,
                   const double mutation_rate){

    auto colony = Colony(colony_size, gene_size, mutation_rate);

    bool found_solution = false;

    int n_generations = 0;

    while (!found_solution){

      colony.mutate_colony();
      colony.find_fitnesses(fitness_function);
      colony.sort_fitnesses();

      found_solution = (colony.current_top_fitness == 0);

      std::cout << "ctf " << colony.current_top_fitness << std::endl;

      colony.cells[0].genes.t().print("top genes");

      if (!found_solution) {
        colony.make_next_generation(selection_rate);
      }

      std::cout << "----" << std::endl;

      n_generations++;
    }


    return {colony.cells[0].genes, n_generations};

}

}
