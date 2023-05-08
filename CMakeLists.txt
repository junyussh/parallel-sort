cmake_minimum_required(VERSION 3.12)

project(my_program)
# Set the C compiler to use with MPICH
set(CMAKE_C_COMPILER mpicc)

# Set the C++ compiler to use with MPICH
set(CMAKE_CXX_COMPILER mpicxx)
add_subdirectory(src)

