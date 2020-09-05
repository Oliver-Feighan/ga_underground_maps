#include "genes.h"

namespace gaus::genetic_algorithm {

void
Cell::make_genes(const int gene_length) {

  genes =
      arma::randi<arma::uvec>(gene_length, arma::distr_param(0, 1));

}

void
Cell::mutate(const double mutation_rate) {

  const int n_mutations = std::round(mutation_rate * genes.n_elem);

  const auto random_indices =
      arma::randi<arma::uvec>(n_mutations,
                              arma::distr_param(0, genes.n_elem));

  genes(random_indices) =
      arma::randi<arma::uvec>(n_mutations, arma::distr_param(0, 1));

}

Cell::Cell(const int t, const int gene_length, const double f) {
  tag = t;
  make_genes(gene_length);
  fitness = f;
}

void
Colony::make_colony(const int n_cells,
                    const int gene_length) {

  cells.reserve(gene_length);

  for (int i = 0; i < n_cells; i++) {
    Cell cell_i = Cell(i, gene_length, NAN);
    cells[i] = cell_i;

  }
}


Colony::Colony(const int size, const int gene_length, const double m_rate) {
  make_colony(size, gene_length);
  colony_size = size;
  assert(m_rate < 1);
  mutation_rate = m_rate;
  current_top_fitness = NAN;

}

void
Colony::find_fitnesses(
    const std::function<double(arma::uvec)> & fitness_function) {
  for (auto & cell : cells) {
    cell.fitness = fitness_function(cell.genes);

  }
}

void
Colony::sort_fitnesses() {
  std::sort(cells.begin(), cells.end(), [](Cell & a, Cell & b) {
    return a.fitness > b.fitness;

  });

  current_top_fitness = cells[0].fitness;
}

void
Colony::mutate_colony() {
  for (auto & cell : cells) {
    cell.mutate(mutation_rate);

  }
}



}