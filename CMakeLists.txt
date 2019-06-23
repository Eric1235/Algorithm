# cmake_minimum_required(VERSION <specify CMake version here>)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithm src/adt/LinkedList.cpp src/adt/LinkedList.h src/adt/LinkedNode.h src/tree/BinarySearchTree.cpp src/tree/BinarySearchTree.h src/adt/Node.h src/adt/List.cpp src/adt/List.h src/heap/BinaryHeap.cpp src/heap/BinaryHeap.h)