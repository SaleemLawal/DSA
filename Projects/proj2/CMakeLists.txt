cmake_minimum_required(VERSION 3.24)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj2
        Game.h
        Ingredient.h
        proj2.cpp
        Shop.h Game.cpp Shop.cpp)
