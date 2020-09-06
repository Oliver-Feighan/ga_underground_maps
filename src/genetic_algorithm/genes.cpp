#include "genes.h"

namespace gaus::genetic_algorithm {

arma::uvec
Cell::make_genes(const int gene_length) {

  return
      arma::randi<arma::uvec>(gene_length, arma::distr_param(0, 1));

}

void
Cell::mutate(const double mutation_rate) {

  const int n_mutations = std::round(mutation_rate * genes.n_elem);

  const auto random_indices =
      arma::randi<arma::uvec>(n_mutations,
                              arma::distr_param(0, genes.n_elem - 1));

  genes(random_indices) =
      arma::randi<arma::uvec>(n_mutations, arma::distr_param(0, 1));

}

std::vector<Cell>
Colony::make_colony(const int n_cells,
                    const int gene_length) {

  std::vector<Cell> initial_cells;

  for (int i = 0; i < n_cells; i++) {
    initial_cells.push_back(Cell(i, gene_length, NAN));

  }

  return initial_cells;
}

void
Colony::find_fitnesses(
    const std::function<int(arma::uvec)> & fitness_function) {
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

void
Colony::evolve(const double selection){
  const int n_survivors = std::round(selection * colony_size);

  const std::vector<Cell> survivors = cells(cells.begin(), cells.begin() + n_survivors);


}

}