cmake_minimum_required(VERSION 3.21)
project(311_SmartToyPointer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

add_executable(311_SmartToyPointer main.cpp)
