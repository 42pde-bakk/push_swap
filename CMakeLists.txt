cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 90)

file(GLOB Dir1_Sources RELATIVE "src" "*.c")
file(GLOB solver_files RELATIVE "src/solver" "*.c")
file(GLOB Dir1_Headers RELATIVE "include" "*.h")

add_executable(push_swap ${Dir1_Sources} ${Dir1_Headers} ${solver_files})

include_directories(libft/include)
include_directories(libc_vector/include)
include_directories(getnextline/include)
include_directories(ft_printf/include)
include_directories(include)
