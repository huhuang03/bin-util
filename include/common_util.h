//
// Created by huhua on 2022/12/23.
//

#ifndef PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
#define PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
namespace reader_util {

bool isFileExists(const std::string &path);

/**
 * This will print charArray append with a new line.
 */
void printCharArray(const char* src, int len);

void printAsHex(const char* src, int len);

/**
 * char array to int little ending
 */
int charArray2Int(const void* charArray, int len);
}
#endif //PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
