cmake_minimum_required(VERSION 3.12)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphs main.cpp DijkstraArray.cpp DijkstraArray.h Vertex.cpp Vertex.h)