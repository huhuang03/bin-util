//
// Created by huhua on 2025/1/28.
//

#ifndef TYPES_H
#define TYPES_H
#include <cstdint>
#include <fstream>

namespace bu {
namespace type {

class Type {
  int _len;
  void *rawBytes = nullptr;
public:
  explicit Type(int len);
  virtual ~Type();
  int getLen() const;
  char const *getRawBytes() const;
  void read(std::ifstream &f) const;
};

class ByteArray: public Type {
  public:
    explicit ByteArray(int len);
};

class U16: public Type {
  public:
    U16();
    uint16_t value() const;
};

class U32: public Type {
  public:
    U32();
    uint32_t value() const;
    static U32 create(std::ifstream &f);
};
}
}

#endif //TYPES_H
