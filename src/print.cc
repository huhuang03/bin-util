//
// Created by huhua on 2025/1/27.
//
#include <iostream>
#include <bin_util/print.h>

std::ostream & operator<<(std::ostream &out, const AsHex &asHex) {
  const auto* p = static_cast<const unsigned char *>(asHex.src);
  out << "0x";
  for (int i = 0; i < asHex.len; i++) {
    printf("%02x", *(p + i));
    if (i != asHex.len -1) {
      std::cout << asHex.divider;
    }
  }
  return out;
}

AsHex bu::print::asHex(const void *src, int len, const std::string &divider) {
  return AsHex {
    src, len, divider
  };
}

std::ostream& bu::print::hex(std::ostream& os, const void *src, const int len, const std::string& divider) {
  const auto* p = static_cast<const unsigned char *>(src);
  os << "0x";
  for (int i = 0; i < len; i++) {
    printf("%02x", *(p + i));
    if (i != len -1) {
      std::cout << divider;
    }
  }
  return os;
}
