add_library(reader-util
        common_util.cc
        file_reader.cc
        content.cc
        section.cc
        file_reader.cc

        ../include/i_file_reader.h
        ../include/file_reader.h
        ../include/content.h
        ../include/section.h
        ../include/reader_util.h)

target_include_directories(reader-util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
