#include <gtest/gtest.h>
#include <stack.hpp>

TEST(PushNPop, test1) {
  task1::Stack<int> S;
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
  task2::Stack<int> S;
  S.push_emplace(1, 2, 4);
  EXPECT_EQ(S.head(), 4);
  S.pop();
  EXPECT_EQ(S.head(), 2);
  S.pop();
  EXPECT_EQ(S.head(), 1);
  EXPECT_THROW({S.pop();}, std::runtime_error);
  EXPECT_THROW({S.head();}, std::runtime_error);
  S.push(10);
  EXPECT_EQ(S.head(), 10);
}
