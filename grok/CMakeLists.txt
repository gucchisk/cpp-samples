cmake_minimum_required(VERSION 3.0)

project(grok-sample)

add_executable(main main.cc)

set(CMAKE_CXX_FLAGS "-v -Wl,-v")

target_include_directories(main PRIVATE /usr/local/include)
target_link_directories(main PUBLIC /usr/local/lib)
target_link_libraries(main grok)
