//
// Created by hwf on 2022/12/16.
//

#include <iostream>
#include <fstream>
#include "../include/common_util.h"

void reader_util::printAsHex(const char *src, int len) {
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

void reader_util::printCharArray(const char *src, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << src[i];
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
