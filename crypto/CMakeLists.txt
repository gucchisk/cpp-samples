cmake_minimum_required(VERSION 2.8)

project(crypto)

if(APPLE)
  if(NOT DEFINED OPENSSL_ROOT_DIR)
    set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
  endif()
endif()

find_package(OpenSSL REQUIRED)

link_libraries(OpenSSL::Crypto)
include_directories(.)

add_executable(hash hash/hash.cc)

add_executable(hkdf kdf/hkdf.cc)

add_executable(pbkdf2 kdf/pbkdf2.cc)
