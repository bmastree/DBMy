cmake_minimum_required(VERSION 3.29)
project(DBMy)

set(CMAKE_CXX_STANDARD 20)

add_executable(DBMy
        sources
        main.cpp
        interface/compiler.cpp
)
