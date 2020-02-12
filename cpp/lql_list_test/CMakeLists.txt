cmake_minimum_required(VERSION 3.5)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#配置项目名称PROJECT_NAME，相当于设置了一个变量，${PROJECT_NAME} = list_test
project(list_test LANGUAGES CXX)

#简单的项目只需要配置这两句
include_directories(./include)
add_executable(lql_${PROJECT_NAME} ./src/list.cpp ./src/test.cpp)
