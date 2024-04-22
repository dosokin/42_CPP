#include "ClapTrap.hpp"

int main() {
    ClapTrap brosky("brosky");
    ClapTrap notbrosky;
    notbrosky = brosky;
    brosky.attack("ops");
    brosky.takeDamage(3);
    brosky.beRepaired(2);

    for (size_t i = 0; i<12; i++)
    {
        notbrosky.takeDamage(2);
        notbrosky.attack("oppps");
        notbrosky.beRepaired(1);
    }
}