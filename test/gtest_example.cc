#include <gtest/gtest.h>

TEST(hello_gtest, add) {
  int got = 200'000;
  EXPECT_EQ(200'000, got);
}
