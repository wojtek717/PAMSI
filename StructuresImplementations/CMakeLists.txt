cmake_minimum_required(VERSION 3.12)
project(StructuresImplementations)

set(CMAKE_CXX_STANDARD 14)

add_executable(StructuresImplementations main.cpp Container.h List.h Stack.h Queue.h PriorityContainer.h PriorityQueue.h Map.h catch.hpp)