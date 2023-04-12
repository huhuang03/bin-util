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

  EXPECT_EQ(reader_util::toUint32("\x00\x00\xff\xff"), 4294901760);
  EXPECT_EQ(reader_util::toUint32("\x00\x00\x00\x01"), 16777216);
  EXPECT_EQ(reader_util::toUint32("\x00\x00\x00\xff"), 4278190080);
  EXPECT_EQ(reader_util::toUint32("\x00\x00\xff\x00"), 16711680);

  EXPECT_EQ(reader_util::toUint64("\x00\x00\x00\x00\x00\x00\xff\xff"), 18446462598732840960ull);
  EXPECT_EQ(reader_util::toUint64("\x00\x00\x00\x00\x00\x00\x00\x01"), 72057594037927936ull);
  EXPECT_EQ(reader_util::toUint64("\x00\x00\x00\x00\x00\x00\x00\xff"), 18374686479671623680ull);
  EXPECT_EQ(reader_util::toUint64("\x00\x00\x00\x00\x00\x00\xff\x00"), 71776119061217280ull);
  EXPECT_EQ(reader_util::toUint64("\x01\x00\x00\x00\x00\x00\x00\x00"), 1ull);

  EXPECT_EQ(reader_util::toInt16("\xff\xff"), -1);
  EXPECT_EQ(reader_util::toInt16("\x00\x01"), 256);
  EXPECT_EQ(reader_util::toInt16("\x00\xff"), -256);
  EXPECT_EQ(reader_util::toInt16("\xff\x00"), 255);

  EXPECT_EQ(reader_util::toInt32("\x00\x00\xff\xff"), -65536);
  EXPECT_EQ(reader_util::toInt32("\x00\x00\x00\x01"), 16777216);
  EXPECT_EQ(reader_util::toInt32("\x00\x00\x00\xff"), -16777216);
  EXPECT_EQ(reader_util::toInt32("\x00\x00\xff\x00"), 16711680);

  EXPECT_EQ(reader_util::toInt64("\x00\x00\x00\x00\x00\x00\xff\xff"), -281474976710656ll);
  EXPECT_EQ(reader_util::toInt64("\x00\x00\x00\x00\x00\x00\x00\x01"), 72057594037927936ll);
  EXPECT_EQ(reader_util::toInt64("\x00\x00\x00\x00\x00\x00\x00\xff"), -72057594037927936ll);
  EXPECT_EQ(reader_util::toInt64("\x00\x00\x00\x00\x00\x00\xff\x00"), 71776119061217280ll);
  EXPECT_EQ(reader_util::toInt64("\x01\x00\x00\x00\x00\x00\x00\x00"), 1ll);


  EXPECT_EQ(reader_util::toUint16BigEndian("\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toUint16BigEndian("\x00\x01"), 1);
  EXPECT_EQ(reader_util::toUint16BigEndian("\x00\xff"), 255);
  EXPECT_EQ(reader_util::toUint16BigEndian("\xff\x00"), 65280);

  EXPECT_EQ(reader_util::toUint32BigEndian("\x00\x00\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toUint32BigEndian("\x00\x00\x00\x01"), 1);
  EXPECT_EQ(reader_util::toUint32BigEndian("\x00\x00\x00\xff"), 255);
  EXPECT_EQ(reader_util::toUint32BigEndian("\x00\x00\xff\x00"), 65280);

  EXPECT_EQ(reader_util::toUint64BigEndian("\x00\x00\x00\x00\x00\x00\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toUint64BigEndian("\x00\x00\x00\x00\x00\x00\x00\x01"), 1);
  EXPECT_EQ(reader_util::toUint64BigEndian("\x00\x00\x00\x00\x00\x00\x00\xff"), 255);
  EXPECT_EQ(reader_util::toUint64BigEndian("\x00\x00\x00\x00\x00\x00\xff\x00"), 65280);
  EXPECT_EQ(reader_util::toUint64BigEndian("\x01\x00\x00\x00\x00\x00\x00\x00"), 72057594037927936ull);

  EXPECT_EQ(reader_util::toInt16BigEndian("\xff\xff"), -1);
  EXPECT_EQ(reader_util::toInt16BigEndian("\x00\x01"), 1);
  EXPECT_EQ(reader_util::toInt16BigEndian("\x00\xff"), 255);
  EXPECT_EQ(reader_util::toInt16BigEndian("\xff\x00"), -256);

  EXPECT_EQ(reader_util::toInt32BigEndian("\x00\x00\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toInt32BigEndian("\x00\x00\x00\x01"), 1);
  EXPECT_EQ(reader_util::toInt32BigEndian("\x00\x00\x00\xff"), 255);
  EXPECT_EQ(reader_util::toInt32BigEndian("\x00\x00\xff\x00"), 65280);

  EXPECT_EQ(reader_util::toInt64BigEndian("\x00\x00\x00\x00\x00\x00\xff\xff"), 65535);
  EXPECT_EQ(reader_util::toInt64BigEndian("\x00\x00\x00\x00\x00\x00\x00\x01"), 1);
  EXPECT_EQ(reader_util::toInt64BigEndian("\x00\x00\x00\x00\x00\x00\x00\xff"), 255);
  EXPECT_EQ(reader_util::toInt64BigEndian("\x00\x00\x00\x00\x00\x00\xff\x00"), 65280);
  EXPECT_EQ(reader_util::toInt64BigEndian("\x01\x00\x00\x00\x00\x00\x00\x00"), 72057594037927936ll);
}