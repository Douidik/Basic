cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(basic-engine)
project(sandbox)

include(Extern.cmake)

include_directories(src/Basic/)

add_subdirectory(src/Basic)
add_subdirectory(src/Sandbox)