cmake_minimum_required(VERSION 3.15)

project(GAUS)

find_library(Armadillo REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(GAUS
               src/run/main.cpp
               src/genetic_algorithm/genes.cpp
)

target_link_libraries(GAUS Boost)