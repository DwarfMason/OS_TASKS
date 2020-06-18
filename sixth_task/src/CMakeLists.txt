cmake_minimum_required(VERSION 3.16)
project(Task8 C)

set(CMAKE_C_STANDARD 11)

add_executable(crc crc.c)
add_executable(check-csum check-csum.c)
add_executable(create-csum create-csum.c)
add_executable(check-xor check-xor.c)
add_executable(check-fletcher check-fletcher.c)
