cmake_minimum_required(VERSION 3.24)

add_subdirectory(../cmake-tools cmake-tools)
ensure_vcpkg()

project(bin-util)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# stupid, should jump to src/CMakeLists.txt
add_subdirectory(src)
add_subdirectory(test)