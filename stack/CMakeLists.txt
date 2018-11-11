cmake_minimum_required(VERSION 3.12)
project(stack C)

set(CMAKE_C_STANDARD 99)

add_library(stack_double  common/stack-double/source/stack.c )

add_executable(mains postfix-prefix-notation/main.c)

target_link_libraries(mains stack_double)