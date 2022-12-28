add_library(reader-util src/common_util.cc
        src/content.cc include/content.h src/section.cc include/section.h include/reader_util.h)

target_include_directories(reader-util INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
