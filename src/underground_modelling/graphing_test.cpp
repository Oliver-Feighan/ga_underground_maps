#define BOOST_TEST_MODULE graphing_test

#include <boost/test/included/unit_test.hpp>

#include "underground_modelling/graphing.h"

BOOST_AUTO_TEST_CASE(test){
  
  using namespace gaus::underground_modelling;
  
  const arma::umat adjacency =
      {{0, 1, 1},
       {1, 0, 0},
       {1, 0, 0}};
  
  const auto graph = make_graph(adjacency);
  
}

