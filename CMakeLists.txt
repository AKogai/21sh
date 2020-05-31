cmake_minimum_required(VERSION 3.10)
project(21sh C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_library(my_lib STATIC IMPORTED)

set_target_properties(my_lib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libft/libft.a")

file(GLOB SRC "includes/*.h" "src/*.c" "srcs/builtin/*.c" "srcs/read/*.c"
        "srcs/exec/*.c" "srcs/lexer/*.c" "srcs/parser/*.c" "libft/libft.h")

add_executable(21sh ${SRC})

include_directories(libft includes src srcs/builtin srcs/read srcs/lexer
        srcs/parser srcs/exec)

target_link_libraries(21sh my_lib -ltermcap)
