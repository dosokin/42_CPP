#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }

    if (!isCalculValid(argv[1]))
        return (1);

    try {
        executeCalcul(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}