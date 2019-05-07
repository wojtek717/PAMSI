cmake_minimum_required(VERSION 3.12)
project(GrafyNowe)

set(CMAKE_CXX_STANDARD 14)

add_executable(GrafyNowe main.cpp MatrixGraph.cpp MatrixGraph.h Graph.cpp Graph.h Vertex.cpp Vertex.h Edge.h Edge.cpp ListGraph.cpp ListGraph.h)