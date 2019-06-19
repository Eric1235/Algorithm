# cmake_minimum_required(VERSION <specify CMake version here>)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithm src/adt/List.cpp src/adt/List.h src/adt/Node.h src/adt/const_iterator.h src/tree/BinarySearchTree.cpp src/tree/BinarySearchTree.h src/adt/const_iterator.h)