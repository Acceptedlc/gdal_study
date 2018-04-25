#include <gtest/gtest.h>

int foobar(void)
{
  return 1;
}

TEST(foobar, test)
{
  ASSERT_EQ(1, foobar());
}
