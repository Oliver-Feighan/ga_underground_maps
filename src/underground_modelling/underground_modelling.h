#ifndef TESTS_UNDERGROUND_MODELLING_H
#define TESTS_UNDERGROUND_MODELLING_H

#include <functional>

#include <armadillo>

#include "underground_modelling/graphing.h"

namespace gaus::underground_modelling {

class Model{

  public:

  StationCoordinates station_coords;
  CostParameters cost_params;

  Model(const StationCoordinates &s_coords,
        const CostParameters &c_params) {

    station_coords = s_coords;
    cost_params = c_params;

  }

  std::function<double(arma::umat)> fitness_function =
      [&station_coords = station_coords, &cost_params = cost_params]
      (const arma::umat &genes){

      arma::umat adjacency = arma::symmatu(genes);

      adjacency.diag().zeros();

      const double connectivity = check_connectivity(adjacency);

      const double cost = calculate_cost(adjacency, station_coords, cost_params);

      const double terminal_stations = find_terminal_stations(adjacency);

      return connectivity * cost * terminal_stations;
    };





};


}

#endif