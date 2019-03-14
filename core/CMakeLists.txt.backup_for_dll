cmake_minimum_required (VERSION 2.8)

project (CORE)

# include_directories(./) 可以指定.h头文件目录
add_library(${PROJECT_NAME} SHARED 
    ./src/core.cpp 
    ./src/string_process.cpp 
    ./src/functions.cpp
    ./src/simple_chain_model.cpp
    ./src/word_chain_model.cpp
    ./src/word_chain_count.cpp
    ./src/word_chain_word.cpp
    ./src/simple_chain_word.cpp
    ./src/simple_chain_count.cpp
)


# 自定义输出dll的名称
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Core")