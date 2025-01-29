//
// Created by huhua on 2025/1/28.
//
#include <bin_util/read.h>

#include "bin_util/convert.h"

uint32_t bu::read::uint32(std::ifstream &f) {
  char buffer[4] = {0};
  f.read(buffer, 4);
  return convert::u32(buffer);
}
