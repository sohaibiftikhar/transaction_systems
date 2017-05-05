cmake_minimum_required(VERSION 2.8.9)
project(transaction_systems)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set (CMAKE_CXX_STANDARD 11)

# Bring the headers into the project
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

add_executable(trans_system ${SOURCES})
