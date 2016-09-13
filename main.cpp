#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>

#include <errno.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "lps.hpp"


int main(int argc, char **argv)
{
    assert(argc == 2);

    int fd = open(argv[1], O_RDONLY);
    assert(fd);

    struct stat fd_stat;
    assert(fstat(static_cast<int>(fd), &fd_stat) == 0);
    assert(S_ISREG(fd_stat.st_mode));

    void* s = mmap(0, fd_stat.st_size, PROT_READ, MAP_SHARED, fd, 0);
    assert(s != MAP_FAILED);
    assert(close(fd) == 0);

    auto result = lps(static_cast<const char*>(s), fd_stat.st_size);
    std::string result_substr {result.first, result.second}; 
    std::cout << result_substr << std::endl;

    assert(munmap(s, fd_stat.st_size) == 0);
    return 0;
}
