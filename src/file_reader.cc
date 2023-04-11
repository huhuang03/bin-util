//
// Created by huhua on 2023/4/9.
//

#include <utility>

#include "../include/reader_util/file_reader.h"
#include "../include/reader_util/common_util.h"

int16_t reader_util::FileReader::readInt16() {
  char buffer[2];
  this->fs.read(buffer, 2);
  return reader_util::toInt16(buffer);
}

int32_t reader_util::FileReader::readInt32() {
  char buffer[4];
  this->fs.read(buffer, 4);
  return reader_util::toInt32(buffer);
}

int64_t reader_util::FileReader::readInt64() {
  char buffer[8];
  this->fs.read(buffer, 8);
  return reader_util::toInt64(buffer);
}

uint16_t reader_util::FileReader::readUInt16() {
  char buffer[2];
  this->fs.read(buffer, 2);
  return reader_util::toUint16(buffer);
}

uint32_t reader_util::FileReader::readUInt32() {
  char buffer[4];
  this->fs.read(buffer, 4);
  return reader_util::toUint32(buffer);
}

uint64_t reader_util::FileReader::readUInt64() {
  char buffer[8];
  this->fs.read(buffer, 8);
  return reader_util::toUint64(buffer);
}

void reader_util::FileReader::read(char *buffer, int len) {
  this->fs.read(buffer, len);
}


int16_t reader_util::FileReader::peekInt16() {
  char buffer[2];
  this->fs.readsome(buffer, 2);
  return reader_util::toInt16(buffer);
}

int32_t reader_util::FileReader::peekInt32() {
  char buffer[4];
  this->fs.readsome(buffer, 4);
  return reader_util::toInt32(buffer);
}

int64_t reader_util::FileReader::peekInt64() {
  char buffer[8];
  this->fs.readsome(buffer, 8);
  return reader_util::toInt64(buffer);
}

uint16_t reader_util::FileReader::peekUInt16() {
  char buffer[2];
  this->fs.readsome(buffer, 2);
  return reader_util::toUint16(buffer);
}

uint32_t reader_util::FileReader::peekUInt32() {
  char buffer[4];
  this->fs.readsome(buffer, 4);
  return reader_util::toUint32(buffer);
}

uint64_t reader_util::FileReader::peekUInt64() {
  char buffer[8];
  this->fs.readsome(buffer, 8);
  return reader_util::toUint64(buffer);
}

void reader_util::FileReader::peekBuffer(char *buffer, int len) {
  this->fs.readsome(buffer, len);
}

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

