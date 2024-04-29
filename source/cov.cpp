#include <iostream>

static int i = 0;
int ccov(void)
{
    std::cout << "cover!" << std::endl;
    if (i != 0) {
        i++;
    }
    return 0; // Result: Illegal instruction
}

