#include "graphing.h"

namespace gaus::underground_modelling {

Graph
make_graph(const arma::umat &adj_mat){

  Graph g;

  const auto connections = arma::find(adj_mat == 1);



  return g;

}


}