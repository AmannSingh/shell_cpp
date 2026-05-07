cmake_minimum_required(VERSION 3.16)

project(shell_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(shell_cpp ${SOURCES})

target_include_directories(shell_cpp
    PRIVATE
        include
)