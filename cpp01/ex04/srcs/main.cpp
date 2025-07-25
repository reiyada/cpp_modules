#include "../includes/replace.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "ERROR: invalid arguments. Try './ex04 <filename> <s1> <s2>'"
            << std::endl;
        return 1;
    }

    ReplaceFile replace(argv[1], argv[2], argv[3]);
    if (!replace.process())
        return 1;
    return 0;
}