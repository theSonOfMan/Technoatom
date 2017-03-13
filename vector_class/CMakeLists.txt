cmake_minimum_required(VERSION 3.6)
project(vector_class)

set(CMAKE_CXX_STANDARD 11)

set (HEADERS vector_class.h)
set (SOURCES vector_class.cpp)
add_library(vector_class_library ${HEADERS} ${SOURCES})

set(SOURCE_FILES vector_test.cpp)
add_executable(vector_class_executable ${SOURCE_FILES})
target_link_libraries(vector_class_executable vector_class_library)