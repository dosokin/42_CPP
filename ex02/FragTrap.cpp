#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap()
{
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " constructor got successfully called!" << std::endl;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& Other) : ClapTrap(Other)
{
        std::cout << "FragTrap " << Other._name << " copy constructor got successfully called!" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& Other)
{
    ClapTrap::operator=(Other);
    std::cout << "FragTrap " << Other._name << " copy assignment constructor got successfully called!" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " destructor got successfully called!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " want a lot to do a high five!" << std::endl;
}