//
// Created by huhua on 2023/4/9.
//

#ifndef READER_UTIL_INCLUDE_I_FILE_READER_H_
#define READER_UTIL_INCLUDE_I_FILE_READER_H_
#include <string>
#include <fstream>

namespace reader_util {
class IFileReader {
 public:
  virtual char readByte() = 0;
  virtual int16_t readInt16() = 0;
  virtual int32_t readInt32() = 0;
  virtual int64_t readInt64() = 0;
  virtual uint16_t readUInt16() = 0;
  virtual uint32_t readUInt32() = 0;
  virtual uint64_t readUInt64() = 0;
  virtual void read(char* buffer, int len) = 0;
  /**
   * read string null terminal.
   */
  virtual std::string readString() = 0;

  virtual char peekByte() = 0;
  virtual int16_t peekInt16() = 0;
  virtual int32_t peekInt32() = 0;
  virtual int64_t peekInt64() = 0;
  virtual uint16_t peekUInt16() = 0;
  virtual uint32_t peekUInt32() = 0;
  virtual uint64_t peekUInt64() = 0;
  virtual void peekBuffer(char* buffer, int len) = 0;

  /**
   * Allow repeat close
   */
  virtual void close() = 0;
};
}
#endif //READER_UTIL_INCLUDE_I_FILE_READER_H_
