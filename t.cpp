#include "lps.hpp"
#include "gmock/gmock.h"

// based on https://www.rosettacode.org/wiki/Palindrome_detection#C.2B.2B
inline bool
is_palindrome(const char *s, std::size_t length) {
    using std::equal;
    using std::reverse_iterator;

    return equal(s, s+length/2, reverse_iterator<const char*>{s+length});
}


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


::testing::AssertionResult IsCorrectLPS(const char *expected, std::pair<const char*, std::size_t> &&result) {
    auto result_cstring = result.first;
    auto result_len = result.second;
    auto expected_char = expected;

    std::size_t compared = 0;

    for(; *expected_char != '\0'; ++expected_char, ++result_cstring, ++compared) {
        if(*expected_char != *result_cstring) {
            return ::testing::AssertionFailure() <<
                "expected='" << expected << "', " <<
                "but got '" << result.first << "' [:" << result.second << "]";
        }
    }

    if(compared != result_len) {
        return ::testing::AssertionFailure() << 
                "expected='" << expected << "', " <<
                "and got '" << result.first << "'[:" << result.second << "], (STRINGS MATCH) " <<
                "however the reported length shall be " << strlen(expected);
    }

    if(!is_palindrome(result.first, result.second)) {
        return ::testing::AssertionFailure() <<
                "Whoops, everything seems good but the result is not a palindrome!";
    }

    return ::testing::AssertionSuccess();
}

#define EXPECT_LPS_EQ(expected, test_string) EXPECT_TRUE(IsCorrectLPS((expected), lps(test_string)))

TEST(LPS, CString) {
    EXPECT_LPS_EQ("", "");
    EXPECT_LPS_EQ("A", "A");
    EXPECT_LPS_EQ("A", "AB");
    EXPECT_LPS_EQ("A", "ABC");

    EXPECT_LPS_EQ("ABA", "ABA");
    EXPECT_LPS_EQ("ABABA", "ABABA");
    EXPECT_LPS_EQ("BBB", "ABBBC");

    EXPECT_LPS_EQ("A", "ABCDEF");
    EXPECT_LPS_EQ("FEDCABACDEF", "FEDCABACDEF");
    EXPECT_LPS_EQ("ABA", "FEDC#ABACDEF");

    EXPECT_LPS_EQ("A", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    EXPECT_LPS_EQ("ZZZ", "ABCZZZ");
}


int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
