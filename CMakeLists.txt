cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

add_executable(push_swap
		src/solver/main.c
		src/stack/stack.c
		src/utils.c
		include/push_swap.h
		include/utils.h
		include/stack.h
		include/operations.h
		include/checker.h
		src/operations/operations.c
		src/operations/swap.c
		src/operations/push.c
		src/operations/rotate.c
		src/operations/reverse_rotate.c
		src/checker/checker.c
		src/stack/print_stacks.c
		src/stack/stack_operations.c
		src/stack/stack_checks.c
		src/parsing.c
		src/solver/bogosort.c
		include/solver.h
		src/solver/bruteforce.c include/vector.h src/vector/vector.c include/opcode.h)

include_directories(libft/include)
include_directories(getnextline/include)
include_directories(ft_printf/include)
include_directories(include)
