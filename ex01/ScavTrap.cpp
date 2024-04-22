#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " constructor got successfully called!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& Other) : ClapTrap(Other)
{
    std::cout << "ScavTrap " << Other._name << " copy constructor got successfully called!" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& Other)
{
    std::cout << "ScavTrap " << Other._name << " copy assignment constructor got successfully called!" << std::endl;
    ClapTrap::operator=(Other);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (!(this->_hitPoints))
    {
        std::cout << "ScavTrap " << this->_name << " has no _hitPoints, he cant attack anybody!" << std::endl;
        return;
    }
    if (!(this->_energyPoints))
    {
        std::cout << "ScavTrap " << this->_name << " has no _energyPoints, he cant attack anybody!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void        ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in ma Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor got successfully called!" << std::endl;
}