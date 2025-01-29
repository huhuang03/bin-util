//
// Created by huhua on 2025/1/28.
//

#ifndef CONVERT_H
#define CONVERT_H

#include <cstdint>

namespace bu {
namespace convert {
uint32_t u32(const char* buffer);
uint16_t u16(const char* buffer);
uint64_t u64(const char* buffer);
int16_t i16(const char* buffer);
int32_t i32(const char* buffer);
int64_t i64(const char* buffer);
}
}
#endif //CONVERT_H
