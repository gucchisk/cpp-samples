cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -DBOOST_NO_CXX11_VARIADIC_TEMPLATES)
include_directories(/usr/local/opt/boost/include/)
#include_directories(/usr/local/opt/boost@1.55/include/)

add_library(hello SHARED hello.cc)
