#include "graphing.h"

#include <boost/graph/connected_components.hpp>

namespace gaus::underground_modelling {

Graph
make_graph(const arma::umat &adj_mat){

  assert(adj_mat.is_symmetric());

  Graph g;

  const arma::uvec connections = arma::find(adj_mat == 1);

  const auto [n_rows, n_cols] = arma::size(adj_mat);

  assert(n_rows == n_cols);

  for(const auto connection : connections){

    const auto vertex_a = connection / n_rows;
    const auto vertex_b = connection % n_rows;

    add_edge(vertex_a, vertex_b, g);

  }

  return g;

}


double
check_connectivity(const arma::umat &adjacency){

  const auto graph = make_graph(adjacency);

  std::vector<int> component(num_vertices(graph));

  return connected_components(graph, &component[0]);

}


arma::mat
outer_difference(const arma::vec &vec){

  const auto n_elem = vec.n_elem;

  arma::mat mat = arma::zeros(arma::size(n_elem, n_elem));

  for(int i = 0; i < n_elem; i++){
    for(int j = 0; j < i; j++){

      mat(i, j) = vec(i) - vec(j);
      mat(j, i) = vec(j) - vec(i);

    }
  }

  return mat;
}


arma::mat
find_distances(const StationCoordinates &station_coord){

  const auto x = outer_difference(station_coord.x);
  const auto y = outer_difference(station_coord.y);

  const auto distances = arma::sqrt(arma::square(x) + arma::square(y));

  return distances;

}


double
calculate_cost(const arma::umat &adjacency,
               const StationCoordinates &station_coord,
               const CostParameters &cp){

  const auto all_distances = find_distances(station_coord);

  const auto built_distances = all_distances % adjacency;

  //0.5 to stop double counting
  return 0.5 * (arma::accu(built_distances * cp.cost_per_unit)
                + arma::accu(adjacency) * cp.base_cost);
}


double
find_terminal_stations(const arma::umat &adjacency){

  const auto n_connections = arma::sum(adjacency, 1);

  return 1. + arma::find(n_connections <= 1).eval().n_elem;

}

}