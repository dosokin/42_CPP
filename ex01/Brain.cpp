#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& Other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = Other._ideas[i];
}

Brain&  Brain::operator=(const Brain& Other)
{
    std::cout << "Brain assignment copy constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = Other._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}