cmake_minimum_required(VERSION 3.23)
project(labbb C)

set(CMAKE_C_STANDARD 11)

add_executable(labbb main.c structure_functions.c structure_functions.h memory_functions.c memory_functions.h main_header.h process_text.c process_text.h memory_allocation_for_text.c memory_allocation_for_text.h error_output.c error_output.h define.h)
