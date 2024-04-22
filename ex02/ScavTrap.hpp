#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public :
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& Other);
    ScavTrap&   operator=(const ScavTrap& Other);
    ~ScavTrap();

    void    attack(const std::string& target);
    void    guardGate();
};

#endif