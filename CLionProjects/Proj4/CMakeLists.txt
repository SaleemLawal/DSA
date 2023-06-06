cmake_minimum_required(VERSION 3.24)
project(Proj4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj4 Game.h Game.cpp proj3.cpp Bomb.cpp Dart.cpp Monkey.cpp Basic.cpp Boomerang.cpp Bloon.cpp)
