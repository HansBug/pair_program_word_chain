cmake_minimum_required (VERSION 2.8)

project (CORE_LIB)

include_directories(./)
add_library(${PROJECT_NAME} SHARED core.cpp)
