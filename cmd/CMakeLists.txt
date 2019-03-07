cmake_minimum_required (VERSION 2.8)

project (Wordlist)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# LINK_DIRECTORIES("C:/Desktop/pair_program_word_chain/core/build")
# target_link_libraries( ${PROJECT_NAME} libcore)

# 添加 getopt_pp 子目录
add_subdirectory(lib/getopt_pp)
target_link_libraries( ${PROJECT_NAME} getopt_pp)

