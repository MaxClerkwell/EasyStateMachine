cmake_minimum_required(VERSION 3.10)

# Projektname
project(StateMachineDemo)

# C++ Standard setzen
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Unterordner "include" hinzufügen
include_directories(include)


add_executable(StateMachineDemo src/main.cpp)
