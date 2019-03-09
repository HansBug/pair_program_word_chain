cmake_minimum_required (VERSION 2.8)

project (wordlist)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})


# 添加 getopt_pp 子目录
add_subdirectory(lib/getopt_pp)
target_link_libraries( ${PROJECT_NAME} getopt_pp)

# 关于动态链接库的东东
# https://stackoverflow.com/questions/37282838/do-i-need-to-distribute-a-header-file-and-a-lib-file-with-a-dll
# https://stackoverflow.com/questions/45912651/how-to-specify-where-to-find-a-shared-library-using-cmake
#
# https://docs.microsoft.com/en-us/windows/desktop/dlls/creating-a-simple-dynamic-link-library
# https://docs.microsoft.com/en-us/windows/desktop/dlls/using-load-time-dynamic-linking
# https://docs.microsoft.com/en-us/windows/desktop/dlls/using-run-time-dynamic-linking
# https://docs.microsoft.com/en-us/cpp/build/exporting-from-a-dll-using-declspec-dllexport?view=vs-2017
# 为什么使用dllimport https://stackoverflow.com/questions/57999/what-is-the-difference-between-dllexport-and-dllimport
#
# 提示找不到DLL, https://stackoverflow.com/questions/44909846/cmake-exe-cant-find-dll

# 添加共享dll库，将找到的结果存入CORE_LIB变量中
find_library(CORE_LIB NAME Core.dll PATHS ../core/build/)
# 链接动态链接库
target_link_libraries( ${PROJECT_NAME} ${CORE_LIB})
# 将找到的DLL复制一份到与可执行文件相同的路径中
# file(COPY ${CORE_LIB} DESTINATION ${CMAKE_BINARY_DIR})
# CMAKE常见变量 https://www.cnblogs.com/xianghang123/p/3556425.html

# 修改CMAKE输出目录：https://stackoverflow.com/questions/543203/cmake-runtime-output-directory-on-windows
# SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
# SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
# SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
# SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
# SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
# SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

# 自动复制dll文件, https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake?rq=1
# 将相对路径转换成绝对路径，默认相对的路径是CMakeLists.txt所在路径，不过可以自己指定
get_filename_component(absolute_path_of_build_dir "./build" REALPATH)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               ${CORE_LIB} ${absolute_path_of_build_dir}/)


# 自动将生成的可执行文件和DLL复制一份到BIN中
get_filename_component(absolute_path_of_BIN "../BIN/" REALPATH)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  $<TARGET_FILE:${PROJECT_NAME}> ${absolute_path_of_BIN}/Wordlist.exe)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_if_different
                  ${CORE_LIB} ${absolute_path_of_BIN})