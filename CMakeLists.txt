cmake_minimum_required(VERSION 3.0)

project(HelloWorld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -fsanitize=address -O0 -fprofile-arcs -ftest-coverage")

#add_subdirectory(source)
add_subdirectory(tests)
