cmake_minimum_required(VERSION 3.23)
project(lab9_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab9_2 main.c memory.c memory.h errors.c errors.h io.c io.h process.c process.h)
