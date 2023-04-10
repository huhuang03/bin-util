include(CTest)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/master.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(read_util_test read_util_test.cc)
target_link_libraries(read_util_test GTest::gtest_main reader-util)
include(GoogleTest)
gtest_discover_tests(read_util_test)
#target_link_libraries(test-read-util reader-util)
#add_test(NAME test-reader-util COMMAND test-reader-util)