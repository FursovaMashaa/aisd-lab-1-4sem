#include<tree.cpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;
using namespace function;

TEST(InsertTest, InsertSingleNode) {
    Node<int>* root = nullptr;
    MySet<int> a;
    a.insert(3);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->_value, 3);
    EXPECT_EQ(root->_left, nullptr);
    EXPECT_EQ(root->_right, nullptr);
}

