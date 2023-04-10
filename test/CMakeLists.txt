include(CTest)

add_executable(test-read-util test_read_util.cc)
target_link_libraries(test-read-util read-util)
add_test(NAME test-reader-util COMMAND test-reader-util)