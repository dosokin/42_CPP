#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

//    int array[] = {6 ,3, 17, 9, 11};
//    std::vector<int> vec(array, array + 5);
//    sp.floodSpan(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;



//    Span bigsp = Span (11000);
//    srand(time(NULL));
//    for (size_t i = 0; i < 11000; i++)
//    {
//        bigsp.addNumber(rand());
//    }
//    std::cout << bigsp.shortestSpan() << std::endl;
//    std::cout << bigsp.longestSpan() << std::endl;



//    std::cout << std::endl;
//
//    Span bigsp = Span (11000);
//    srand(time(NULL));
//    for (size_t i = 0; i < 11001; i++)
//    {
//        bigsp.addNumber(rand());
//    }
//    std::cout << bigsp.shortestSpan() << std::endl;
//    std::cout << bigsp.longestSpan() << std::endl;
    return 0;
}