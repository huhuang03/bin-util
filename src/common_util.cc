//
// Created by hwf on 2022/12/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../include/bin_util/common_util.h"


template<typename T>
static T toTBigEnding(const char* buffer) {
  T rst = 0;
  int size = sizeof (T);
  for (int i = 0; i < size; i++) {
    rst = rst << 8 | (unsigned char)buffer[i];
  }
  return rst;
}

uint16_t bu::toUint16BigEndian(const char* buffer) {
  return toTBigEnding<uint16_t>(buffer);
}

uint32_t bu::toUint32BigEndian(const char* buffer) {
  return toTBigEnding<uint32_t>(buffer);
}

uint64_t bu::toUint64BigEndian(const char* buffer) {
  return toTBigEnding<uint64_t>(buffer);
}

int16_t bu::toInt16BigEndian(const char* buffer) {
  return toTBigEnding<uint16_t>(buffer);
}

int32_t bu::toInt32BigEndian(const char* buffer) {
  return toTBigEnding<uint32_t>(buffer);
}

int64_t bu::toInt64BigEndian(const char* buffer) {
  return toTBigEnding<uint64_t>(buffer);
}



void bu::printCharArray(const void *src, int len) {
  const auto* p = reinterpret_cast<const unsigned char *>(src);
  for (int i = 0; i < len; i++) {
    std::cout << p[i];
  }
  std::cout << std::endl;
}

int bu::charArray2Int(const void *charArray, const int len) {
    const auto* valueArray = static_cast<const unsigned char *>(charArray);
    int rst = 0;
    for (int i = len - 1; i >= 0; i--) {
        rst = rst << (2 << 8);
        rst += valueArray[i];
    }
    return rst;
}

bool bu::isFileExists(const std::string &path) {
  std::ifstream f(path.c_str());
  auto rst = f.good();
  if (f.is_open()) {
    f.close();
  }
  return rst;
}

std::string bu::toHex(uint64_t val) {
  // how to do this?
  std::ostringstream oss;
  oss << "0x" << std::hex << std::endl;
  return oss.str();
}

std::string bu::toStrAsLEHex(const void *data, int len) {
  const auto* p = reinterpret_cast<const unsigned char *>(data);
  std::stringstream ss;
  ss << "0x";
  bool begin = false;
  for (int i = len - 1; i >= 0; i--) {
    if (*(p + i) != 0) {
      begin = true;
    }
    ss << std::hex << std::setfill('0') << std::setw(2);
    if (begin) {
      ss << static_cast<unsigned>(*(p + i));
      ss << " ";
    }
  }
  return ss.str();
}
