//
// Created by huhua on 2022/12/23.
//

#ifndef PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
#define PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
namespace reader_util {

uint16_t toUint16(const char* buffer);
uint32_t toUint32(const char* buffer);
uint64_t toUint64(const char* buffer);
int16_t toInt16(const char* buffer);
int32_t toInt32(const char* buffer);
int64_t toInt64(const char* buffer);

bool isFileExists(const std::string &path);

/**
 * This will print charArray append with a new line.
 */
void printCharArray(const void* src, int len);

void printAsHex(const void* src, int len);

/**
 * for 0x00 11 22 00 return 0x22 11 00
 */
std::string toStrAsLEHex(const void *data, int len);


/**
 * char array to int little ending
 */
int charArray2Int(const void* charArray, int len);

std::string toHex(uint64_t val);

}
#endif //PE_READER_THIRDPART_READER_UTIL_INCLUDE_COMMON_UTIL_H_
