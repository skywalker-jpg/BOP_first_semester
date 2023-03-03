cmake_minimum_required(VERSION 3.23)
project(untitled10 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled10 main.c input_output.c input_output.h memory.c memory.h sort_funcs.c sort_funcs.h structure.h mylib.h error_funcs.c error_funcs.h define.h)
