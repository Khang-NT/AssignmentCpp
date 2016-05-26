cmake_minimum_required(VERSION 3.5)
project(Assignment_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ModelBase.cpp ModelBase.hpp IOHelper.cpp IOHelper.hpp)
add_executable(Assignment_Cpp ${SOURCE_FILES})