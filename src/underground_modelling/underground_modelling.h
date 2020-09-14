#ifndef TESTS_UNDERGROUND_MODELLING_H
#define TESTS_UNDERGROUND_MODELLING_H

#include <functional>

#include <armadillo>

#include "underground_modelling/graphing.h"

namespace gaus::underground_modelling {

struct StationCoordinates{

  arma::vec x;
  arma::vec y;
};

struct UndergroundModelParams {

  StationCoordinates station_coords;

};

class Model{

  public:

  StationCoordinates station_coords;

  Model(const StationCoordinates &s_coords, const double foo){

    station_coords = s_coords;

  }

  std::function<double(arma::umat)> fitness_function =
      [station_coords = station_coords](const arma::umat &genes){

    arma::umat adjacency = arma::symmatu(genes);
    adjacency.diag().zeros();

    const Graph graph = make_graph(adjacency);

    const double connectivity = check_connectivity(graph);

    const double cost = 0.0;

    const double terminal_stations = 0.0;

    return connectivity * cost * terminal_stations;
  };

};


}

#endif