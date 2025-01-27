//
// Created by hwf on 2022/12/20.
//

#include "../include/bin_util/content.h"

bu::Content::Content(int size): _size(size) {
    _content = static_cast<unsigned char *>(malloc(size));
}

void bu::Content::read(std::istream &in) {
  // how can I read?
  in.read(reinterpret_cast<char *>(this->_content), this->_size);
}

int bu::Content::size() {
    return this->_size;
}

void bu::Content::setContent(char *content) {
    // 怎么做？
    if (this->_size <= 0) {
        return;
    }
    memcpy(this->_content, content, _size);
}

void bu::Content::free() {
    if (this->_content != nullptr) {
        ::free(this->_content);
        this->_content = nullptr;
    }
    this->_size = 0;
}

bu::Content::~Content() {
    this->free();
}
