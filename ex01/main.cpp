#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap brosky("brosky");
    ScavTrap notbrosky;
    notbrosky = brosky;
    brosky.attack("ops");
    brosky.takeDamage(3);
    brosky.beRepaired(2);
    brosky.guardGate();

    for (size_t i = 0; i<12; i++)
    {
        notbrosky.takeDamage(2);
        notbrosky.attack("oppps");
        notbrosky.beRepaired(1);
    }
}