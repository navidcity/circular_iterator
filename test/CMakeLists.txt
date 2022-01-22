project(circular_iterator_test LANGUAGES CXX)

add_executable(circular_iterator_test_increment)

target_sources(circular_iterator_test_increment PRIVATE
    circular_iterator_test_increment.cpp)

target_link_libraries(circular_iterator_test_increment
    PRIVATE
    circular_iterator::circular_iterator)

add_test(NAME increment
    COMMAND circular_iterator_test_increment
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
