//
// Created by huhua on 2023/4/9.
//

#ifndef READER_UTIL_INCLUDE_FILE_READER_H_
#define READER_UTIL_INCLUDE_FILE_READER_H_
#include <string>
#include <fstream>
#include "./i_file_reader.h"

namespace reader_util {
class FileReader: IFileReader {
 private:
  std::ifstream fs;
  ~FileReader();
 public:
  std::string path;
  FileReader(std::string path);
 public:
  int16_t readInt16();
  int32_t readInt32();
  int64_t readInt64();
  uint16_t readUInt16();
  uint32_t readUInt32();
  uint64_t readUInt64();
  void readBuffer(char* buffer, int len);

  int32_t peekInt32();
  int64_t peekInt64();
  uint16_t peekUInt16();
  uint32_t peekUInt32();
  uint64_t peekUInt64();
  void peekBuffer(char* buffer, int len);
  /**
   * Close if need.
   */
  void close();
};
}
#endif //READER_UTIL_INCLUDE_FILE_READER_H_
