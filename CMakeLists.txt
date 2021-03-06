cmake_minimum_required(VERSION 3.15)

add_definitions(-DARMA_DONT_USE_WRAPPER)

project(GAUS)

message("")

message("building G.A.U.S. - the genetic algorithm for undergound solutions")

message("")

find_package(Armadillo REQUIRED)

if (${ARMADILLO_FOUND})
    message("found armadillo " ${ARMADILLO_VERSION_STRING})
endif ()

message("")

find_package(Boost REQUIRED)
if (${BOOST_FOUND})
    message("found boost " ${Boost_VERSION_STRING})
endif ()

message("")


set(CMAKE_CXX_STANDARD 17)

add_library(LIBGAUS

            src/genetic_algorithm/genes.cpp
            src/genetic_algorithm/genetic_algorithm.cpp

            src/underground_modelling/underground_modelling.cpp
            src/underground_modelling/graphing.cpp

)


target_link_libraries(LIBGAUS ${ARMADILLO_LIBRARIES})

add_executable(GAUS

        src/run/main.cpp

)

target_link_libraries(GAUS LIBGAUS)

include_directories(src)
include_directories(SYSTEM ${ARMADILLO_INCLUDE_DIRS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})


project(tests)
enable_testing()

set(BOOST_INCLUDE_DIRS)

add_executable(binary_test src/run/binary_number_test.cpp)

target_include_directories(binary_test PRIVATE ${BOOST_INCLUDE_DIRS})

target_link_libraries(binary_test LIBGAUS)

add_test(Binary_test test1 COMMAND binary_test)



add_executable(graphing_test src/underground_modelling/graphing_test.cpp)

target_include_directories(graphing_test PRIVATE ${BOOST_INCLUDE_DIRS})

target_link_libraries(graphing_test LIBGAUS)

add_test(Graphing_test test2 COMMAND graphing_test)