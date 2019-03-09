cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(GUIApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)

# Make this a GUI application on Windows
# 加入这个就不会出现黑框
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

# 加入这个就可以自动将 .ui 文件转换为 .h 文件
set(CMAKE_AUTOUIC ON)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})


# 查找QTWidgets库
find_package(Qt5Widgets REQUIRED)
# 链接QT 动态链接库
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)


# 添加Core核心计算库
find_library(CORE_LIB NAME libCORE_LIB PATHS ../core/build/)
# 链接动态链接库
target_link_libraries( ${PROJECT_NAME} ${CORE_LIB})
# 将找到的DLL复制一份到与可执行文件相同的路径中
file(COPY ${CORE_LIB} DESTINATION ${CMAKE_BINARY_DIR})