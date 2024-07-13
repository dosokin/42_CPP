#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstddef>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span{
public:
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    Span(unsigned int N);
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    const std::vector<int> &getArray() const;
    unsigned int getN() const;

    void floodSpan(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
private:
    Span();

    unsigned int N;
    std::vector<int> array;
};

#endif