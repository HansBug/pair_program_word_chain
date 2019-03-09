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
find_library(CORE_LIB NAME Core.dll PATHS ../core/build/)
# 链接动态链接库
target_link_libraries( ${PROJECT_NAME} ${CORE_LIB})

# 自动复制dll文件, https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake?rq=1
# 将相对路径（相对CMakeLists.txt）转换成绝对路径，
get_filename_component(absolute_path_of_build_dir "./build" REALPATH )
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               ${CORE_LIB} ${absolute_path_of_build_dir})

# 自动将生成的可执行文件和DLL复制一份到GUIBIN中
get_filename_component(absolute_path_of_GUIBIN "../GUIBIN/" REALPATH)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  $<TARGET_FILE:${PROJECT_NAME}> ${absolute_path_of_GUIBIN})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  ${CORE_LIB} ${absolute_path_of_GUIBIN})