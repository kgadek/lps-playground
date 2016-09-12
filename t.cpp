#include "lps.hpp"
#include "gmock/gmock.h"


TEST(IsPalindrome, CStringEven) {
    EXPECT_TRUE(is_palindrome("", 0));
    EXPECT_TRUE(is_palindrome("AA", 2));
    EXPECT_TRUE(is_palindrome("ABBA", 4));

    EXPECT_FALSE(is_palindrome("AB", 2));
    EXPECT_FALSE(is_palindrome("ABAB", 4));
}

TEST(IsPalindrome, CStringOdd) {
    EXPECT_TRUE(is_palindrome("A", 1));
    EXPECT_TRUE(is_palindrome("ABA", 3));
    EXPECT_TRUE(is_palindrome("ABCBA", 5));
    EXPECT_TRUE(is_palindrome("ABBBA", 5));

    EXPECT_FALSE(is_palindrome("ABB", 3));
    EXPECT_FALSE(is_palindrome("ABABC", 5));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
