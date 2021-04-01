cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

add_executable(push_swap
        src/main.c
        src/stack.c
        src/utils.c
        includes/push_swap.h
        includes/utils.h
        includes/stack.h
        includes/operations.h
        src/operations/operations.c
        src/operations/swap.c
        src/operations/push.c
        src/operations/rotate.c
        src/operations/reverse_rotate.c)

include_directories(libft)
include_directories(getnextline)
include_directories(ft_printf)
include_directories(includes)
