cmake_minimum_required(VERSION 3.6)
project(BuildYourOwnLisp)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c mpc.h mpc.c)
add_executable(BuildYourOwnLisp ${SOURCE_FILES})