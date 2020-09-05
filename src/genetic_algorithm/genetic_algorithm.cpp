//
// Created by Oliver Feighan on 8/31/20.
//

#include "genetic_algorithm.h"

#include "genes.h"

namespace gaus::genetic_algorithm {

arma::uvec
find_solution(const std::function<double(int, arma::uvec)> &fitness_function,
              const int colony_size,
              const int gene_length,
              const double mutation_rate){

    auto colony = Colony(colony_size, gene_length, mutation_rate);

    return {};
}

}
