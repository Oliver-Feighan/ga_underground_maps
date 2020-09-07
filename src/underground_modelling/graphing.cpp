#include "graphing.h"

#include <boost/config.hpp>

#include <boost/property_map/property_map.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>

namespace gaus::underground_modelling {

using namespace boost;

void
make_graph(){

  typedef adjacency_list<vecS, vecS, undirectedS> Graph;

  Graph gruh;

  add_edge(0, 1, gruh);

}


}