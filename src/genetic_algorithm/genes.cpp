#include "genes.h"

namespace gaus::genetic_algorithm {

std::vector<Cell>
make_cells(const int n_cells,
           const int n_genes){

  std::vector<Cell> cells(n_cells);

  for(int i = 0; i < n_cells; i++){
    const arma::vec random = arma::round(arma::randu(n_genes));

    cells[i] =
        {i, arma::conv_to<arma::uvec>::from(random), arma::datum::inf};
  }

}

std::vector<Cell>
breed_genes(){}

}