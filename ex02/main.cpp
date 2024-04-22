#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap brosky("brosky");
    FragTrap notbrosky;
    notbrosky = brosky;
    brosky.attack("ops");
    brosky.takeDamage(3);
    brosky.beRepaired(2);
    brosky.highFivesGuys();

    for (size_t i = 0; i<12; i++)
    {
        notbrosky.takeDamage(2);
        notbrosky.attack("oppps");
        notbrosky.beRepaired(1);
    }
}