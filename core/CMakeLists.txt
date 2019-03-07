cmake_minimum_required (VERSION 2.8)

project (Demo2)


add_library(core SHARED core.cpp)

# SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)
# set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "your name")