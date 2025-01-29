//
// Created by huhua on 2023/4/9.
//

#include <boost/filesystem.hpp>

#include "../include/bin_util/file_reader.h"
#include "../include/bin_util/common_util.h"
#include "bin_util/convert.h"

namespace fs = boost::filesystem;

void bu::FileReader::align(int size) {
  long long pos = this->fs.tellg();
  auto mod = size % pos;
  if (mod != 0) {
    this->fs.seekg(pos + size - mod);
  }
}

char bu::FileReader::readByte() {
  char rst;
  this->fs.read(&rst, 1);
  return rst;
}

int16_t bu::FileReader::readInt16() {
  char buffer[2];
  this->fs.read(buffer, 2);
  if (this->endian_ == LITTLE) {
    return convert::i16(buffer);
  }
  return toInt16BigEndian(buffer);
}

int32_t bu::FileReader::readInt32() {
  char buffer[4];
  this->fs.read(buffer, 4);
  if (this->endian_ == LITTLE) {
    return convert::i32(buffer);
  }
  return toInt32BigEndian(buffer);
}

int64_t bu::FileReader::readInt64() {
  char buffer[8];
  this->fs.read(buffer, 8);
  if (this->endian_ == LITTLE) {
    return convert::i64(buffer);
  }
  return toInt64BigEndian(buffer);
}

uint16_t bu::FileReader::readUInt16() {
  char buffer[2];
  this->fs.read(buffer, 2);
  if (this->endian_ == LITTLE) {
    return convert::u16(buffer);
  }
  return toUint16BigEndian(buffer);
}

uint32_t bu::FileReader::readUInt32() {
  char buffer[4] = {0};
  this->fs.read(buffer, 4);
  if (this->endian_ == LITTLE) {
    return convert::u32(buffer);
  }
  return toUint32BigEndian(buffer);
}

uint64_t bu::FileReader::readUInt64() {
  char buffer[8];
  this->fs.read(buffer, 8);
  if (this->endian_ == LITTLE) {
    return convert::u64(buffer);
  }
  return toUint64BigEndian(buffer);
}

void bu::FileReader::read(char *buffer, int len) {
  this->fs.read(buffer, len);
}

char bu::FileReader::peekByte() {
  char rst;
  this->fs.readsome(&rst, 1);
  return rst;
}

int16_t bu::FileReader::peekInt16() {
  char buffer[2];
  this->fs.readsome(buffer, 2);
  if (this->endian_ == LITTLE) {
    return convert::i16(buffer);
  }
  return toInt16BigEndian(buffer);
}

int32_t bu::FileReader::peekInt32() {
  char buffer[4];
  this->fs.readsome(buffer, 4);
  if (this->endian_ == LITTLE) {
    return convert::i32(buffer);
  }
  return toInt32BigEndian(buffer);
}

int64_t bu::FileReader::peekInt64() {
  char buffer[8];
  this->fs.readsome(buffer, 8);
  if (this->endian_ == LITTLE) {
    return convert::i64(buffer);
  }
  return toInt64BigEndian(buffer);
}

uint16_t bu::FileReader::peekUInt16() {
  char buffer[2];
  this->fs.readsome(buffer, 2);
  if (this->endian_ == LITTLE) {
    return convert::u16(buffer);
  }
  return toUint16BigEndian(buffer);
}

uint32_t bu::FileReader::peekUInt32() {
  char buffer[4];
  this->fs.readsome(buffer, 4);
  if (this->endian_ == LITTLE) {
    return convert::u32(buffer);
  }
  return toUint32BigEndian(buffer);
}

uint64_t bu::FileReader::peekUInt64() {
  char buffer[8];
  this->fs.readsome(buffer, 8);
  if (this->endian_ == LITTLE) {
    return convert::u64(buffer);
  }
  return toUint64BigEndian(buffer);
}

void bu::FileReader::peekBuffer(char *buffer, int len) {
  this->fs.readsome(buffer, len);
}

bu::FileReader::~FileReader() {
  if (this->fs.is_open()) {
    this->fs.close();
  }
}

void bu::FileReader::close() {
  if (this->fs.is_open()) {
    this->fs.close();
  }
}

bu::FileReader::FileReader(const std::string &path, bu::Endian endian): path(path), endian_(endian) {
  if (!fs::exists(this->path)) {
    throw std::invalid_argument("path not exists: " + path);
  }
//  fs.open(this->path.c_str(), std::ios::binary);
  fs.open(this->path.c_str());
  if (!fs.is_open()) {
    throw std::invalid_argument("can't open file: " + path);
  }
}

void bu::FileReader::changeEndian(const Endian endian) {
  endian_ = endian;
}

std::string bu::FileReader::readString() {
  std::string rst;
  std::getline(this->fs, rst, '\x0');
  return rst;
}
