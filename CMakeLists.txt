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

)


target_link_libraries(LIBGAUS ${ARMADILLO_LIBRARIES})

add_executable(GAUS

        src/run/main.cpp

        src/underground_modelling/underground_modelling.cpp
        src/underground_modelling/graphing.cpp

)

target_link_libraries(GAUS LIBGAUS)

include_directories(src)
include_directories(SYSTEM ${ARMADILLO_INCLUDE_DIRS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})


project(tests)
enable_testing()

set(BOOST_INCLUDE_DIRS)

add_executable(test_executable src/run/binary_number_test.cpp)

target_include_directories(test_executable PRIVATE ${BOOST_INCLUDE_DIRS})

target_link_libraries(test_executable LIBGAUS)

add_test(Binary_test test1 COMMAND test_executable)