cmake_minimum_required(VERSION 3.5)
project(Assignment_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Account.cpp
        Account.hpp
        CMakeLists.txt
        HashSum.hpp
        IOHelper.hpp
        json.hpp
        main.cpp
        MenuHelper.cpp
        MenuHelper.hpp
        ModelBase.hpp
        readme.md HashSum.cpp GlobalVariants.hpp Utils.hpp Utils.cpp GlobalVariants.cpp AdminProcess.cpp AdminProcess.hpp)

add_executable(Assignment_Cpp ${SOURCE_FILES})