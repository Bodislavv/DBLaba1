cmake_minimum_required(VERSION 3.20)
project(DBLab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(DBLab1 main.c Master.h Ind.h Slave.h Input.h Output.h Validation.h Movie.h Actor.h)
