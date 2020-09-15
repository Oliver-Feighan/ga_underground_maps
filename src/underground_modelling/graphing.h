#ifndef GAUS_GRAPHING_H
#define GAUS_GRAPHING_H

#include <armadillo>

#include <boost/config.hpp>

#include <boost/property_map/property_map.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>

namespace gaus::underground_modelling {

using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS> Graph;


struct StationCoordinates{

  arma::vec x;
  arma::vec y;
};

struct CostParameters {

  double base_cost;
  double cost_per_unit;

};

struct UndergroundModelParams {

  StationCoordinates station_coords;
  CostParameters cost_params;

};


double
calculate_cost(const arma::umat &adjacency,
               const StationCoordinates &station_coord,
               const CostParameters &cp);

double
find_terminal_stations(const arma::umat & adj_mat);

double
check_connectivity(const arma::umat & adjacency);

}

#endif //GAUS_GRAPHING_H
