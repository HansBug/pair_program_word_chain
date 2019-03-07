cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(GUIApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


# 指定生成目标
#add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 隐藏控制台
# https://cmake.org/pipermail/cmake/2008-March/020576.html
IF(WIN32)  
    SET(GUI_TYPE WIN32)  
ENDIF(WIN32)
IF (APPLE) 
    SET(GUI_TYPE MACOSX_BUNDLE)  
ENDIF (APPLE)
add_executable(${PROJECT_NAME} ${GUI_TYPE} ${DIR_SRCS})


# 查找QT目录
find_package(Qt5Widgets REQUIRED)
# 链接QT 动态链接库
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# 添加 getopt_pp 子目录
add_subdirectory(lib/getopt_pp)
# 链接模块
target_link_libraries( ${PROJECT_NAME} getopt_pp)