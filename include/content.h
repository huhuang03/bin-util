//
// Created by hwf on 2022/12/20.
//

#ifndef PE_READER_CONTENT_H
#define PE_READER_CONTENT_H

#include <iostream>

namespace reader_util {

/**
 * any better name?
 *
 * For now, we don't allow resize.
 */
class Content {
 public:
  Content(int size);
  ~Content();
  int size();
  virtual void read(std::istream &in);

  /**
   * set _content as content, size is Content's size.
   */
  void setContent(char *content);

 private:
  int _size;
  unsigned char *_content;
  void free();
};
}

#endif //PE_READER_CONTENT_H
