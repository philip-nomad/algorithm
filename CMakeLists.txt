cmake_minimum_required(VERSION 3.7)
project(pageReplacement)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES etc/kosaraju.cpp)
add_executable(pageReplacement ${SOURCE_FILES})