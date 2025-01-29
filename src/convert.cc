//
// Created by huhua on 2025/1/28.
//
#include <bin_util/convert.h>

template<typename T>
static T toT(const char* buffer) {
  T rst = 0;
  const int size = sizeof (T);
  for (int i = 0; i < size; i++) {
    rst = rst << 8 | static_cast<unsigned char>(buffer[size - 1 - i]);
  }
  return rst;
}

int64_t bu::convert::i64(const char *buffer) {
  return toT<int64_t>(buffer);
}

int32_t bu::convert::i32(const char *buffer) {
  return toT<int32_t>(buffer);
}

int16_t bu::convert::i16(const char *buffer) {
  return toT<int16_t>(buffer);
}

uint64_t bu::convert::u64(const char *buffer) {
  return toT<uint64_t>(buffer);
}


uint32_t bu::convert::u32(const char *buffer) {
  return toT<uint32_t>(buffer);
}

uint16_t bu::convert::u16(const char *buffer) {
  return toT<uint16_t>(buffer);
}