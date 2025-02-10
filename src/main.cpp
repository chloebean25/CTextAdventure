#ifdef _WIN32
#include <windows.h>

#endif

#include <iostream>
#include <vector>
#include "fogpi/Math.hpp"
#include <time.h>
#include <stdio.h>
#include <string.h>



int Add(int &_a, int &_b)
{
    _a = _a * 2;
    return _a + _b;
}

int main(int argc, char* argv[])
{
    char e = 'a';

    const char* message = "Hello, World!";

    int a[] = {1,2,3,4};

    printf("%s\n", message);
  
    return 0;
}
