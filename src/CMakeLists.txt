set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(bin-util
        common_util.cc
        file_reader.cc
        content.cc
        section.cc
        file_reader.cc

        ../include/bin_util/i_file_reader.h
        ../include/bin_util/file_reader.h
        ../include/bin_util/content.h
        ../include/bin_util/section.h
        ../include/bin_util/endian.h
        ../include/bin_util/bin_util.h)

find_package(Boost REQUIRED COMPONENTS filesystem)

target_include_directories(bin-util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include")
target_link_libraries(bin-util Boost::filesystem)