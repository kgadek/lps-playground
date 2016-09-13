Longest palindrome subsequence
==============================

This is a playground to compare Haskell with C++ in terms of performance.

Please note that this is *not* the correct implementation! It only detects "odd" palindromes.

To compile::

    mkdir -p build && cd build && cmake .. && make


Quick guide
-----------

- ``lps.hpp`` -- the actual implementation, provides ``lps``
- ``main.cpp`` -- entry point, does mmap and calls ``lps``
- ``t.cpp`` -- tests

