//
// Created by huhua on 2025/1/27.
//

#ifndef PRINT_H
#define PRINT_H
#include <string>

struct AsHex {
  const void* src;
  int len;
  std::string divider;
  friend std::ostream& operator<<(std::ostream& out, const AsHex &asHex);
};

namespace bu {
namespace print {
std::ostream& hex(std::ostream& os, const void* src, int len, const std::string& divider = " ");
AsHex asHex(const void* src, int len, const std::string& divider = " ");
}
}
#endif //PRINT_H
