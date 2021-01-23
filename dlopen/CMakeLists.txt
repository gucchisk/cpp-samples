cmake_minimum_required(VERSION 2.8)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cc manager.cc)

set(CMAKE_MACOSX_RPATH 1)
add_library(idclient SHARED idclient.cc)
add_library(infoclient SHARED infoclient.cc)
