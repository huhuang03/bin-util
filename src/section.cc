//
// Created by hwf on 2022/12/20.
//

#include <utility>

#include "../include/bin_util/section.h"

bu::Section::Section(int size, std::vector<Content> fields): Content(size), _fields(std::move(fields)) {}

// how to create a empty field??
bu::Section::Section(int size) : Section(size, std::vector<Content>()) {
}

void bu::Section::read(std::istream &in) {
  Content::read(in);
  // set all info?
}
void bu::Section::setFields(std::vector<Content> fields) {
  this->_fields = std::move(fields);
}
