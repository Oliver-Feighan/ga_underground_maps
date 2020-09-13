#ifndef TESTS_UNDERGROUND_MODELLING_H
#define TESTS_UNDERGROUND_MODELLING_H

#include <functional>

#include <armadillo>

namespace underground_modelling {

class Model{

  public:
  std::function<void()> fitness_function;

  const std::type_info& gene_type = typeid(arma::umat);

};


}

#endif
