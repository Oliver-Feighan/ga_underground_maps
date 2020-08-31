//
// Created by Oliver Feighan on 8/31/20.
//

#include "fitness_function.h"

namespace gaus::genetic_algorithm{

double
fitness(const Cell &gene,
        const std::function<double(Cell)> &function) {

  return function(gene);
}

arma::vec
get_fitnesses(const std::vector<Cell> &cells){

}

}