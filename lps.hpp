#pragma once

#include <cstring>
#include <algorithm>
#include <iterator>


// based on https://www.rosettacode.org/wiki/Palindrome_detection#C.2B.2B
inline bool is_palindrome(const char *s, std::size_t length) {
    using std::equal;
    using std::reverse_iterator;

    return equal(s, s+length/2, reverse_iterator<const char*>{s+length});
}

