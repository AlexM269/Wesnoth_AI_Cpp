cmake_minimum_required(VERSION 3.24)
project(Wesnoth_AI_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Wesnoth_AI_Cpp
        Player.cpp
        Player.hpp
        Unit.cpp
        Unit.hpp)
