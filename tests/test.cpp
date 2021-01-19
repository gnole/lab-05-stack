#include <gtest/gtest.h>
#include <stack.hpp>
#include <stackNotCopyTypes.hpp>

TEST(PushNPop, test1) {
  Stack<int> S;
  S.push(5);
  EXPECT_EQ(S.head(), 5);
  S.push(3);
  EXPECT_EQ(S.head(), 3);
  S.pop();
  EXPECT_EQ(S.head(), 5);
  int a = 10;
  S.push(a);
  EXPECT_EQ(S.head(), 10);
}

TEST(Push_emplace, test2) {
  StackNotCopyTypes<int> SN;
  SN.push_emplace(1, 2, 4);
  EXPECT_EQ(SN.head(), 4);
  SN.pop();
  EXPECT_EQ(SN.head(), 2);
  SN.pop();
  EXPECT_EQ(SN.head(), 1);
  EXPECT_THROW({SN.pop();}, std::runtime_error);
  EXPECT_THROW({SN.head();}, std::runtime_error);
  SN.push(10);
  EXPECT_EQ(SN.head(), 10);
}
