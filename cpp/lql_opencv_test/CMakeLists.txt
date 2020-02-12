cmake_minimum_required(VERSION 3.5)

project(opencv_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "/home/jiacai_chen/software/opencv/opencv_install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

include_directories(./include
                    ${OpenCV_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/test.cpp)
target_link_libraries(${PROJECT_NAME}
   ${OpenCV_LIBS}
 )
