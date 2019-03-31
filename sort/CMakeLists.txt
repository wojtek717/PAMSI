cmake_minimum_required(VERSION 3.12)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(sort main.cpp Bubble.cpp Bubble.h MergeS.cpp MergeS.h HeapS.cpp HeapS.h)