cmake_minimum_required(VERSION 3.27)
project(ass4_movie_starterG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass4_movie_starterG
        customer.h
        main.cpp
        movie.h
        movieInventory.cpp
        movieInventory.h
        store_test.cpp)
