//
// Created by hwf on 2022/12/20.
//

#include "../include/content.h"

reader_util::Content::Content(int size): _size(size) {
    _content = static_cast<unsigned char *>(malloc(size));
}

void reader_util::Content::read(std::istream &in) {
  // how can I read?
  in.read(reinterpret_cast<char *>(this->_content), this->_size);
}

int reader_util::Content::size() {
    return this->_size;
}

void reader_util::Content::setContent(char *content) {
    // 怎么做？
    if (this->_size <= 0) {
        return;
    }
    memcpy(this->_content, content, _size);
}

void reader_util::Content::free() {
    if (this->_content != nullptr) {
        ::free(this->_content);
        this->_content = nullptr;
    }
    this->_size = 0;
}

reader_util::Content::~Content() {
    this->free();
}
