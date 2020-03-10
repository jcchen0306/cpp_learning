cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test LANGUAGES CXX)
include_directories(./include)
add_executable(cjc_${PROJECT_NAME} ./src/list.cpp ./src/test.cpp)

