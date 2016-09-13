#pragma once

#include <cstring>
#include <algorithm>
#include <iterator>
#include <utility>

#include <iostream>


std::pair<const char*, std::size_t>
lps(const char* s, std::size_t s_length)
{

    const char* longest_palindrome = s;
    std::size_t longest_length = 0;

    const char* s_last = s + s_length - 1;

    const char* curr_center = s;

    for( ; *curr_center != '\0'; ++curr_center)
    {

        std::size_t curr_length = 1;
        const char* left_it = curr_center;
        const char* right_it = curr_center;

        for( ; s < left_it && right_it < s_last; curr_length+=2)
        {
            if( *(--left_it) != *(++right_it))
            {
                ++left_it;
                --right_it;
                break;
            }
        }

        if(curr_length > longest_length)
        {
            longest_palindrome = left_it;
            longest_length = curr_length;
        }
    }

    return std::make_pair(longest_palindrome, longest_length);
}

std::pair<const char*, std::size_t>
inline lps(const char *s)
{
    return lps(s, strlen(s));
}

