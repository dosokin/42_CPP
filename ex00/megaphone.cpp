#include <ctype.h>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (size_t i = 1; i < argc; i++)
        for (size_t j = 0; argv[i][j]; j++)
            std::cout << (char)toupper(argv[i][j]);
    std::cout << std::endl;
    return (0);
}
