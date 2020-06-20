cmake_minimum_required(VERSION 3.17)
project(GEN_RefactorC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GEN_RefactorC
        Customer.cpp
        Customer.h
        main.cpp
        Movie.cpp
        Movie.h
        Rental.h)
