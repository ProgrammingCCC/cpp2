#include "../src/fib.hpp"

#include <gtest/gtest.h>

TEST(FibTest, Ten) {
  Math m = Math();
  ASSERT_EQ(55, m.fib(10));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
