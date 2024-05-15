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

TEST(RandomTest, VectorTest) {
    int a = 1;
    int b = 100;
    size_t n = 5;
    size_t i = 123;

    std::vector<int> result = random(a, b, n, i);

    ASSERT_EQ(result.size(), n);
    for (size_t j = 0; j < n; j++) {
        EXPECT_GE(result[j], a);
        EXPECT_LE(result[j], b);
    }
}

TEST(RandomTest, SingleValueTest) {
    int a = 1;
    int b = 100;
    size_t i = 456;

    int result = random(a, b, i);

    EXPECT_GE(result, a);
    EXPECT_LE(result, b);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}