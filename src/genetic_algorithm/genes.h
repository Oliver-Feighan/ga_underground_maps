//
// Created by Oliver Feighan on 8/31/20.
//

#ifndef GAUS_GENES_H
#define GAUS_GENES_H

#include <armadillo>

namespace gaus::genetic_algorithm {

struct Cell {
  int tag;
  arma::uvec genes;
  double fitness;
};

std::vector<Cell>
make_cells(const int n_cells,
           const int n_genes);

}

#endif //GAUS_GENES_H
