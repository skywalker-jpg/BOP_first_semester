cmake_minimum_required(VERSION 3.23)
project(lab11_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab11_2 main.c file_operations.c file_operations.h memory.c memory.h mylib.c mylib.h structure_operations.c structure_operations.h structure.h change_films_func.c change_films_func.h main_funcs.c main_funcs.h)
