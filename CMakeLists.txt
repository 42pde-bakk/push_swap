cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

add_executable(push_swap algo/main.c algo/push_swap.h algo/stack.c algo/stack.h algo/operations.c algo/operations.h)