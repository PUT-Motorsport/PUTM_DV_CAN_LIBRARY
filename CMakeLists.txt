cmake_minimum_required(VERSION 3.0.0)
project(can_lib VERSION 0.1.0)

add_executable(can_lib main.cpp Src/interface.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
