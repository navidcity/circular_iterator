project(circular_iterator_test LANGUAGES CXX)

add_executable(circular_iterator_test_increment)

target_source(circular_iterator_test_increment
	circular_iterator_test_increment.cpp)

target_link_libraries(MyLibTests
	PRIVATE
	circular_iterator::circular_iterator)

add_test(NAME increment
	COMMAND circular_iterator_test_increment
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIRECTORY}/test)