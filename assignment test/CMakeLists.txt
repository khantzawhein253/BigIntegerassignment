cmake_minimum_required(VERSION 3.25)
project(assignment_test C)

set(CMAKE_C_STANDARD 11)

add_executable(assignment_test main.c BigInteger.h BigInteger.c)
