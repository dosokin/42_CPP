#include "PmergeMe.hpp"
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "Error: Not enough arguments" << std::endl;
        return (1);
    }
    if (argc > 30001)
    {
        std::cerr << "Error: Please be reasonable with amount of arguments\n"
                     "[Using more than 30000 arguments risk to cause a 'stack memory overflow' and will most probably crash the program]" << std::endl;
        return (1);
    }

    //timer initialisation
    struct timeval start = {0, 0}, end = {0, 0};
    unsigned int chrono;

    // VECTOR SORT
    std::vector<int> sortedVector;
    gettimeofday(&start, NULL);
    try {
        sortedVector = vectorSort(argc, argv);
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    gettimeofday(&end, NULL);
    chrono = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printElement(sortedVector, AFTER);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << chrono << " us" << std::endl;

    //reset time structures
    start.tv_sec = 0;
    start.tv_usec = 0;
    end.tv_sec = 0;
    end.tv_usec = 0;

    // DEQUE SORT
    std::deque<int> sortedDeque;
    gettimeofday(&start, NULL);
    try {
        dequeSort(argc, argv);
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    gettimeofday(&end, NULL);
    chrono = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << chrono << " us" << std::endl;

    return (0);

}