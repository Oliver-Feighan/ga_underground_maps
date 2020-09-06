//
// Created by Oliver Feighan on 8/31/20.
//

#ifndef GAUS_GENETIC_ALGORITHM_H
#define GAUS_GENETIC_ALGORITHM_H

#include "genetic_algorithm/genes.h"

namespace gaus::genetic_algorithm {

arma::uvec
find_solution(const std::function<int(arma::uvec)> &fitness_function,
              const int colony_size,
              const int gene_length,
              const double mutation_rate);

}

#endif //GAUS_GENETIC_ALGORITHM_H
