//
// Created by Oliver Feighan on 8/31/20.
//

#ifndef GAUS_GENES_H
#define GAUS_GENES_H

#include <armadillo>

namespace gaus::genetic_algorithm {

class Cell {

public:
  int tag; //an identifer for the cell
  arma::uvec genes; //parameters that define behaviour
  int fitness; //to be populated by the fitness function

  void
  make_genes(const int gene_length);

  void
  mutate(const double mutation_rate);

  Cell(const int t, const int gene_length, const double f);

};

class Colony {
  std::vector<Cell> cells;
  int colony_size;
  double mutation_rate;
  int current_top_fitness = NAN;

private:
  void
  make_colony(const int n_cells, const int gene_length);

public:

  Colony(const int size, const int gene_length, const double m_rate);

  void
  find_fitnesses(const std::function<double(arma::uvec)> & fitness_function);

  void
  sort_fitnesses();

  void
  mutate_colony();

};


}

#endif //GAUS_GENES_H
