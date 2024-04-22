#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
        {
public :
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& Other);
    FragTrap&   operator=(const FragTrap& Other);
    ~FragTrap();

    void    highFivesGuys(void);
};

#endif
