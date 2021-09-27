cmake_minimum_required(VERSION 3.0)
project(life-game VERSION 1.0 LANGUAGES C CXX)

set(SRC user.c tty.c tty.h)

add_executable(game ${SRC})
target_compile_options(game PRIVATE -Wall -Wextra)