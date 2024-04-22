#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
public :
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& Other);
    ClapTrap&   operator=(const ClapTrap& Other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string             _name;
    unsigned int            _hitPoints;
    unsigned int            _energyPoints;
    unsigned int            _attackDamage;
};

#endif