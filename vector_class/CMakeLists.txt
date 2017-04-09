cmake_minimum_required(VERSION 3.6)
project(vector_class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vector_test.cpp vector_class.h vector_clas.h)
add_executable(vector_class_executable ${SOURCE_FILES})