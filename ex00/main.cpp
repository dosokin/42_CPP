#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<unsigned int, double> data;

    if (argc != 2)
    {
        std::cerr << "Error: filename missing" << std::endl;
        return 1;
    }

    try {
        parseDataFile(data);
        treatInputFile(data, argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}