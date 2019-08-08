cmake_minimum_required(VERSION 3.14)
project(MoE_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(MoE_1 main.cpp Expert.cpp Expert.h Gate.cpp Gate.h Node.cpp Node.h)

target_include_directories(MoE_1 PUBLIC armadillo/include)
