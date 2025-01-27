//
// Created by huhua on 2023/4/9.
//

#ifndef READER_UTIL_INCLUDE_FILE_READER_H_
#define READER_UTIL_INCLUDE_FILE_READER_H_
#include <string>
#include <fstream>
#include "./i_file_reader.h"
#include "./endian.h"

namespace bu {
class FileReader: public IFileReader {
 private:
  std::string path;
  std::ifstream fs;
  Endian endian_;

 public:
  FileReader(const std::string &path): FileReader(path, LITTLE) {};
  FileReader(const std::string &path, Endian endian);
  ~FileReader();
 public:
  void align(int size) override;
  std::string readString() override;
  char readByte() override;
  int16_t readInt16() override;
  int32_t readInt32() override;
  int64_t readInt64() override;
  uint16_t readUInt16() override;
  uint32_t readUInt32() override;
  uint64_t readUInt64() override;
  void read(char* buffer, int len) override;

  char peekByte() override;
  int16_t peekInt16() override;
  int32_t peekInt32() override;
  int64_t peekInt64() override;
  uint16_t peekUInt16() override;
  uint32_t peekUInt32() override;
  uint64_t peekUInt64() override;
  void peekBuffer(char* buffer, int len) override;
  /**
   * Close if need.
   */
  void close() override;
  void changeEndian(Endian endian);
};
}
#endif //READER_UTIL_INCLUDE_FILE_READER_H_
