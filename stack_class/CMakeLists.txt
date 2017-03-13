cmake_minimum_required(VERSION 3.4)
project(stack_class)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES stack_class.cpp)
set(HEADERS stack_class.h)
add_library(stack_class_lib ${SOURCES} ${HEADERS})

set(SOURCE_FILES StackTest.cpp)
add_executable(stack_class_executable ${SOURCE_FILES})
target_link_libraries(stack_class_executable stack_class_lib)