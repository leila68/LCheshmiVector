cmake_minimum_required(VERSION 3.17)
project(LCheshmiVector)

set(CMAKE_CXX_STANDARD 17)

add_library(LCheshmiVector STATIC CCustom_vector.cpp)
add_executable(exec main.cpp)
target_link_libraries(exec PUBLIC LCheshmiVector)

add_subdirectory(GoogleTest)