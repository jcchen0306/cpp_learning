cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test LANGUAGES CXX)
include_directories(./include)
add_executable(lql_${PROJECT_NAME} src/test.cpp src/my_function.cpp)
