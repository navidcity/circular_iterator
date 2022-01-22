cmake_minimum_required(VERSION 3.15)

project(circular_iterator_examples
    LANGUAGES CXX
    DESCRIPTION "Example using fetch content for circular_iterator library")

set(CMAKE_CXX_STANDARD_REQUIRED True)

message("This is a ${CMAKE_SYSTEM_NAME} system")

find_package(circular_iterator REQUIRED)

add_subdirectory(dependencies)

add_subdirectory(src)
