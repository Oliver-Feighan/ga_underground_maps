cmake_minimum_required(VERSION 3.15)

add_definitions(-DARMA_DONT_USE_WRAPPER)

project(GAUS)

message("")

message("building G.A.U.S. - the genetic algorithm for undergound solutions")

message("")

find_package(Armadillo REQUIRED)

if( ${ARMADILLO_FOUND} )
    message("found armadillo " ${ARMADILLO_VERSION_STRING})
endif()

message("")

find_package(Boost REQUIRED)
if( ${BOOST_FOUND} )
    message("found boost " ${Boost_VERSION_STRING})
endif()

message("")

set(CMAKE_CXX_STANDARD 17)

add_executable(GAUS
               src/run/main.cpp

               src/genetic_algorithm/genes.cpp
               src/genetic_algorithm/genetic_algorithm.cpp
               src/genetic_algorithm/fitness_function.cpp

)

target_link_libraries(GAUS ${ARMADILLO_LIBRARIES})

include_directories( src )
include_directories(SYSTEM ${ARMADILLO_INCLUDE_DIRS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})