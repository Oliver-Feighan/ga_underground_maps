//
// Created by Oliver Feighan on 8/31/20.
//

#ifndef GAUS_GENES_H
#define GAUS_GENES_H

#include <armadillo>

namespace gaus::genetic_algorithm {

class Cell {
private:
  arma::uvec
  make_genes(const int gene_length);

public:
  int tag; //an identifer for the cell
  arma::uvec genes; //parameters that define behaviour
  int fitness; //to be populated by the fitness function

  void
  mutate(const double mutation_rate);

  Cell(const int t, const int gene_length, const int f) {
    tag = t;
    genes = make_genes(gene_length);
    fitness = f;
  }

};

class Colony {
private:

  std::vector<Cell>
  make_colony(const int n_cells, const int gene_length);

public:
  std::vector<Cell> cells;
  int colony_size;
  double mutation_rate;
  int current_top_fitness = NAN;

  Colony(const int size, const int gene_length, const double m_rate) {
    cells = make_colony(size, gene_length);
    colony_size = size;
    assert(m_rate < 1);
    mutation_rate = m_rate;
  }

  void
  find_fitnesses(const std::function<int(arma::uvec)> & fitness_function);

  void
  sort_fitnesses();

  void
  mutate_colony();

  void
  make_next_generation(const double selection);

};


}

#endif //GAUS_GENES_H
