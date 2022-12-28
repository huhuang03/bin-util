//
// Created by hwf on 2022/12/20.
//

#include <utility>

#include "../include/section.h"

reader_util::Section::Section(int size, std::vector<Content> fields): Content(size), _fields(std::move(fields)) {}

// how to create a empty field??
reader_util::Section::Section(int size) : Section(size, std::vector<Content>()) {
}

void reader_util::Section::read(std::istream &in) {
  Content::read(in);
  // set all info?
}
void reader_util::Section::setFields(std::vector<Content> fields) {
  this->_fields = std::move(fields);
}
