//
// Created by huhua on 2023/4/9.
//
#include "reader_util/reader_util.h"
#include <gtest/gtest.h>

TEST(testToUint16, BasicAssertions) {
  EXPECT_EQ(reader_util::toUint16("\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toUint16("\x00\x01"), 256);
  EXPECT_EQ(reader_util::toUint16("\x00\xff"), 65280);
  EXPECT_EQ(reader_util::toUint16("\xff\x00"), 255);
}