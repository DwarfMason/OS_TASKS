cmake_minimum_required(VERSION 3.15)
project(src C)

set(CMAKE_C_STANDARD 99)

add_executable(aspace aspace.c)
add_executable(example_2 example_2.c)
add_executable(null null.c)
add_executable(malloc_leak malloc_leak.c)
add_executable(malloc_data malloc_data.c)
add_executable(deleted_array deleted_array.c)
target_compile_options(null PRIVATE -g)