#define BOOST_TEST_MODULE graphing_test

#include <boost/test/included/unit_test.hpp>

#include "underground_modelling/graphing.h"

BOOST_AUTO_TEST_SUITE( graphing_tests )

BOOST_AUTO_TEST_CASE( graph ){

  using namespace gaus::underground_modelling;

  const arma::umat adjacency =
      {{0, 1, 1},
       {1, 0, 0},
       {1, 0, 0}};

  const Graph graph = make_graph(adjacency);

  BOOST_TEST(boost::num_edges(graph) == 4);
  BOOST_TEST(boost::num_vertices(graph) == 3);

}

BOOST_AUTO_TEST_CASE( cost ){

  using namespace gaus::underground_modelling;

  const arma::umat adjacency =
      {{0, 1},
       {1, 0}
      };


  const StationCoordinates s_coords =
      {{0, 1},
       {0, 0}
      };


  const auto cost = calculate_cost(adjacency, s_coords, {0.5, 0.2});

  BOOST_TEST(cost == 0.7);
}

BOOST_AUTO_TEST_CASE( terminal_stations ){

  using namespace gaus::underground_modelling;

  const arma::umat adjacency =
      {{0, 0},
       {0, 0}
      };

  const auto f_terminal = find_terminal_stations(adjacency);

  std::cout << "f_terminal " << f_terminal << std::endl;

  BOOST_TEST(f_terminal == 0.5);
}


BOOST_AUTO_TEST_CASE( connectivity ){
  using namespace gaus::underground_modelling;

  const arma::umat adjacency =
      {{0, 1, 0, 0},
       {1, 0, 0, 0},
       {0, 0, 0, 1},
       {0, 0, 1, 0},
      };

  const double connectivity = check_connectivity(adjacency);

  std::cout << "connectivity " << connectivity << std::endl;

  BOOST_TEST(connectivity == 0.5);
}

BOOST_AUTO_TEST_SUITE_END()