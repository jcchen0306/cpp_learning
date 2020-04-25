cmake_minimum_required(VERSION 3.5)

project(opencv_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#这两行是设置opencv库的安装路径和查找该库
set(OpenCV_DIR "/home/jiacai_chen/software/opencv/opencv_install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

#这一行是添加opencv的声明的头文件路径
include_directories(./include ${OpenCV_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} src/test.cpp)

#这一行是为编译生成的可执行程序，中的调用的opencv的函数的实现，在opencv的lib中去链接查找。
target_link_libraries(${PROJECT_NAME}
   ${OpenCV_LIBS}
 )

