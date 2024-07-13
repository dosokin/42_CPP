#include "Span.hpp"

Span::Span(){}

Span::Span(const Span& other) : N(other.getN()){
    *this = other;
}

Span::Span(unsigned int N) : N(N){
}

Span& Span::operator=(const Span& other){
    this->N = other.getN();
    this->array.clear();
    for (std::vector<int>::const_iterator it = other.getArray().begin(); it + 1 != other.getArray().end(); it++){
        this->addNumber(*it);
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if (this->array.size() >= this->N)
        throw std::logic_error("Array is full");
    this->array.push_back(number);
}

unsigned int Span::shortestSpan() const{
    if (this->getArray().size() < 2)
        throw std::logic_error("Not enough elements to return a span");
    unsigned int shortest = (unsigned int)2147483647 * 2;
    std::vector<int> sorted = this->getArray();
    std::sort(sorted.begin(), sorted.end());
    for (std::vector<int>::const_iterator it = this->array.begin(); it + 1 != this->array.end(); it++)
    {
        unsigned int tempo = *(it + 1) - *it;
        if (tempo < shortest)
            shortest = tempo;
    }
    return (shortest);
}

unsigned int Span::longestSpan() const{
    if (this->getArray().size() < 2)
        throw std::logic_error("Not enough elements to return a span");
    std::vector<int> sorted = this->getArray();
    std::sort(sorted.begin(), sorted.end());
    return (sorted.at(sorted.size() - 1) - sorted.at(0));
}

const std::vector<int> &Span::getArray() const{
    return this->array;
}

unsigned int Span::getN() const{
    return this->N;
}

void Span::floodSpan(std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
    for (; it1 != it2 ; it1++)
    {
        this->addNumber(*it1);
    }
}