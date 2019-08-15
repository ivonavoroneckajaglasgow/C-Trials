cmake_minimum_required(VERSION 3.14)
project(MoE_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(MoE_3 main.cpp Node.cpp Node.h Gate.cpp Gate.h Expert.cpp Expert.h NormalExpert.cpp NormalExpert.h NormalParameters.h GateParameters.h)

target_include_directories(MoE_3 PUBLIC armadillo/include)