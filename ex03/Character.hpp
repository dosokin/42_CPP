#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
public:
    Character();
    Character(const std::string& name);
    Character(const Character& Other);
    Character& operator=(const Character& Other);
    ~Character();

    std::string const & getName() const;
    void use(int idx, ICharacter& target);
    void equip(AMateria* m);
    void unequip(int idx);

    AMateria *get_inventory_slot(int idx) const;
private:
    struct unequiped
    {
        AMateria *m;
        unequiped *next;
    };
    std::string _name;
    AMateria*    _inventory[4];
    unequiped*   _droppedItems;
};

#endif
