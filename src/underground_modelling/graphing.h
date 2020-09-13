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

Graph
make_graph(const arma::umat &adj_mat);


}

#endif //GAUS_GRAPHING_H
