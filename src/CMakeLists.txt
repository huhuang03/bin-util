set(CMAKE_CXX_STANDARD 11)
add_library(reader-util
        common_util.cc
        file_reader.cc
        content.cc
        section.cc
        file_reader.cc

        ../include/reader_util/i_file_reader.h
        ../include/reader_util/file_reader.h
        ../include/reader_util/content.h
        ../include/reader_util/section.h
        ../include/reader_util/reader_util.h)

target_include_directories(reader-util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include")