//
// Created by huhua on 2023/4/9.
//

#include <utility>

#include "../include/file_reader.h"
#include "../include/common_util.h"

reader_util::FileReader::FileReader(std::string path): path(std::move(path)) {
  fs.read((char*)this->path.c_str(), std::ios::binary);
}

reader_util::FileReader::~FileReader() {
  if (this->fs.is_open()) {
    this->fs.close();
  }
}

void reader_util::FileReader::close() {
  if (this->fs.is_open()) {
    this->fs.close();
  }
}

int16_t reader_util::FileReader::readInt16() {
  char buffer[2];
  this->fs.read(buffer, 2);
  return reader_util::toUint16(buffer);
}

int32_t reader_util::FileReader::readInt32() {
  return 0;
}

int64_t reader_util::FileReader::readInt64() {
  return 0;
}

uint16_t reader_util::FileReader::readUInt16() {
  return 0;
}
uint32_t reader_util::FileReader::readUInt32() {
  return 0;
}
uint64_t reader_util::FileReader::readUInt64() {
  return 0;
}
void reader_util::FileReader::readBuffer(char *buffer, int len) {

}
int32_t reader_util::FileReader::peekInt32() {
  return 0;
}
int64_t reader_util::FileReader::peekInt64() {
  return 0;
}
uint16_t reader_util::FileReader::peekUInt16() {
  return 0;
}
uint32_t reader_util::FileReader::peekUInt32() {
  return 0;
}
uint64_t reader_util::FileReader::peekUInt64() {
  return 0;
}
void reader_util::FileReader::peekBuffer(char *buffer, int len) {

}
