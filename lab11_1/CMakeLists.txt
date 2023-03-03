cmake_minimum_required(VERSION 3.23)
project(lab11 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab11 main.c mylib.h file_funcs.cpp file_funcs.h file_funcs.c memory.c memory.h)
