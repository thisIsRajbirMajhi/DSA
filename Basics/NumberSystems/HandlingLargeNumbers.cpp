#include <stdio.h>
#include <iostream>
using namespace std;

// int: 32 bit: -2^31 to 2^31 - 1
// long long: 64 bit: -2^63 to 2^63 - 1
// unsigned long long: 64 bit: 0 to 2^64 - 1
// __int128: 128 bit (GCC/Clang extension)

int main()
{
    // Normal integer, up to 64 bits
    long long x = 9223372036854775807LL; // 64 bit
    // Integer up to ~128 bits
    __int128 y = 123456789012345678901234567890; // 128 bit
    

    return 0;
}