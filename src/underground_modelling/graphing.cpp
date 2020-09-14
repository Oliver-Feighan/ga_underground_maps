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
check_connectivity(const Graph &graph){

  std::vector<int> component(num_vertices(graph));

  return 1 / connected_components(graph, &component[0]);

}

}