#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{}

ClapTrap::ClapTrap(std::string name) :
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructor got successfully called!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& Other)
{
    std::cout << "ClapTrap " << Other._name << " copy constructor got successfully called!" << std::endl;
    this->_name = Other._name;
    this->_hitPoints = Other._hitPoints;
    this->_energyPoints = Other._energyPoints;
    this->_attackDamage = Other._attackDamage;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& Other)
{
    std::cout << "ClapTrap " << Other._name << " copy assignment constructor got successfully called!" << std::endl;
    this->_name = Other._name;
    this->_hitPoints = Other._hitPoints;
    this->_energyPoints = Other._energyPoints;
    this->_attackDamage = Other._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor got successfully called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!(this->_hitPoints))
    {
        std::cout << "ClapTrap " << this->_name << " has no _hitPoints, he cant attack anybody!" << std::endl;
        return;
    }
    if (!(this->_energyPoints))
    {
        std::cout << "ClapTrap " << this->_name << " has no _energyPoints, he cant attack anybody!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " life is already at the lowest, he cant take additional damages!" << std::endl;
        return;
    }
    if (amount > this->_hitPoints)
    {
        std::cout << "ClapTrap " << this->_name << " take " << this->_hitPoints << " of damage! " << this->_name << " pvs fell from " << this->_hitPoints << " to 0" << std::endl;
        this->_hitPoints = 0;
        return ;
    }
    unsigned int tempo = this->_hitPoints;
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " take " << amount << " of damage! " << this->_name << " pvs fell from " << tempo << " to " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!(this->_hitPoints))
    {
        std::cout << "ClapTrap " << this->_name << " has no _hitPoints, he cant repair itself!" << std::endl;
        return;
    }
    if (!(this->_energyPoints))
    {
        std::cout << "ClapTrap " << this->_name << " has no _energyPoints, he cant repair itself!" << std::endl;
        return;
    }
    unsigned int tempo = this->_hitPoints;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " get repaired of " << amount << " of health! " << this->_name << " pvs jumped from " << tempo << " to " << this->_hitPoints << std::endl;
    this->_energyPoints--;
}