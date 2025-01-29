set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB_RECURSE _headers "../include/bin_util/*.h")
file(GLOB_RECURSE _src "*.cc")
add_library(bin-util
        ${_src}
        ${_headers}
        )

find_package(Boost REQUIRED COMPONENTS filesystem)

target_include_directories(bin-util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_include_directories(bin-util PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_link_libraries(bin-util Boost::filesystem)