cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_library(my_lib STATIC IMPORTED)

set_target_properties(my_lib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libft/libft.a")

file(GLOB SRC "includes/*.h" "src/*.c" "builtin/*.c" "read_line/*.c"
        #"src/env/*.c"
        #"src/exec/*.c" "src/expansion/*.c" "src/history/*.c"
        #"src/lexer/*.c" "src/line_editing/*.c" "src/main/*.c" "src/parser/*.c"
        #"src/term/*.c" "built_ins/*.c"
        "libft/libft.h")

add_executable(minishell ${SRC})

include_directories(libft includes src built_ins read_line)

target_link_libraries(minishell my_lib -ltermcap)
