# Set the source files for program1
set(SOURCES quicksort.cpp)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
# Create an executable target for program1
add_executable(quicksort ${SOURCES})
