#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain();
}

Dog::Dog(const Dog& other): AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain(other.getBrain());
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment copy constructor called" << std::endl;
    this->type = other.type;
    delete(this->dogBrain);
    this->dogBrain = new Brain(other.getBrain());
    return (*this);
}

Brain       Dog::getBrain() const
{
    return (*this->dogBrain);
}

void        Dog::makeSound() const
{
    std::cout << "gaf gaf" << std::endl;
}

Dog::~Dog()
{
    delete this->dogBrain;
    std::cout << "Dog destructor called" << std::endl;
}