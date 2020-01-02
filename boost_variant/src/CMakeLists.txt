cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib /usr/local/opt/boost@1.55/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib /usr/local/opt/boost/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/build)

add_executable(main main.cc)
target_link_libraries(main hello)
