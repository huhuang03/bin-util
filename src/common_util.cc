//
// Created by hwf on 2022/12/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../include/common_util.h"

uint16_t reader_util::toUint16(const char *buffer) {
  return -1;
}

void reader_util::printAsHex(const void *src, int len) {
  const auto* p = reinterpret_cast<const unsigned char *>(src);
  std::cout << "0x";
  for (int i = 0; i < len; i++) {
    printf("%02x", *(p + i));
    if (i != len -1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void reader_util::printCharArray(const void *src, int len) {
  const auto* p = reinterpret_cast<const unsigned char *>(src);
  for (int i = 0; i < len; i++) {
    std::cout << p[i];
  }
  std::cout << std::endl;
}

int reader_util::charArray2Int(const void *charArray, int len) {
    const auto* valueArray = (const unsigned char *) charArray;
    int rst = 0;
    for (int i = len - 1; i >= 0; i--) {
        rst = rst << (2 << 8);
        rst += valueArray[i];
    }
    return rst;
}

bool reader_util::isFileExists(const std::string &path) {
  std::ifstream f(path.c_str());
  auto rst = f.good();
  if (f.is_open()) {
    f.close();
  }
  return rst;
}

std::string reader_util::toStrAsLEHex(const void *data, int len) {
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