#ifndef TESTS_UNDERGROUND_MODELLING_H
#define TESTS_UNDERGROUND_MODELLING_H

#include <functional>

#include <armadillo>

#include "underground_modelling/graphing.h"

namespace gaus::underground_modelling {

class Model{

  public:

  std::function<double(arma::umat)> fitness_function =
      [](const arma::umat &adjacency){

    const Graph graph = make_graph(adjacency);

    const double connectivity = 0.0;

    const double cost = 0.0;

    const double terminal_stations = 0.0;

    return 5.0;
  };

};


}

#endif