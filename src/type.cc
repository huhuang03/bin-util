//
// Created by huhua on 2025/1/28.
//

#include <bin_util/type.h>
#include <bin_util/convert.h>

bu::type::Type::Type(const int len): _len(len) {
  if (this->_len <= 0) {
    return;
  }
  this->rawBytes = malloc(len);
}

// why free is not right??
bu::type::Type::~Type() {
  // if (this->rawBytes != nullptr) {
  //   // free(this->rawBytes);
  //   this->rawBytes = nullptr;
  // }
}

int bu::type::Type::getLen() const {
  return this->_len;
}

char const *bu::type::Type::getRawBytes() const {
  return static_cast<char const *>(this->rawBytes);
}

void bu::type::Type::read(std::ifstream &f) const {
  f.read(static_cast<char *>(this->rawBytes), sizeof(this->_len));
}

bu::type::ByteArray::ByteArray(const int len): Type(len) {}

bu::type::U16::U16(): Type(2) {
}

uint16_t bu::type::U16::value() const {
  return convert::u16(this->getRawBytes());
}

bu::type::U32::U32(): Type(4) {
}

// U32

bu::type::U32 bu::type::U32::create(std::ifstream &f) {
  U32 rst;
  rst.read(f);
  return rst;
}

uint32_t bu::type::U32::value() const {
  return convert::i32(this->getRawBytes());
}
