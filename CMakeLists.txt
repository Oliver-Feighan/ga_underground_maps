cmake_minimum_required(VERSION 3.15)

find_package(Armadillo REQUIRED)

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

project(GAUS)

add_executable(GAUS

               main.cpp

               genetic_algorithm/genes.cpp
)

target_link_libraries(GAUS ${ARMADILLO_LIBRARIES})