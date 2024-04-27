#include "Character.hpp"

#include <iostream>
#include "AMateria.hpp"

Character::Character()
{
    this->_inventory[0] = NULL;
    this->_inventory[1] = NULL;
    this->_inventory[2] = NULL;
    this->_inventory[3] = NULL;
    this->_droppedItems = NULL;
    std::cout << "Default constructor created a NoName Character" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
    this->_inventory[0] = NULL;
    this->_inventory[1] = NULL;
    this->_inventory[2] = NULL;
    this->_inventory[3] = NULL;
    this->_droppedItems = NULL;
    std::cout << "Name constructor created a " << this->_name << " Character" << std::endl;
}

Character::Character(const Character& Other) : _name(Other.getName())
{
    for (int j = 0; j < 4; j++)
    {
        if (Other._inventory[j])
            this->_inventory[j] = Other.get_inventory_slot(j)->clone();
    }
    std::cout << "Assignment constructor created a " << this->_name << " Character" << std::endl;
}

Character& Character::operator=(const Character& Other)
{
    this->_name = Other.getName();
    for (int j = 0; j < 4; j++) {
        if (this->_inventory[j])
        {
            delete _inventory[j];
            _inventory[j] = NULL;
        }
        if (Other.get_inventory_slot(j))
        {
            this->_inventory[j] = Other.get_inventory_slot(j)->clone();
        }
    }
    std::cout << "Operator constructor created a " << this->_name << " Character" << std::endl;
    return (*this);
}

Character::~Character()
{
    unequiped *last;

    std::cout << "Destructor of " << this->_name << " Character called" << std::endl;
    for (int j = 0; j < 4; j++)
    {
        if (this->_inventory[j])
        {
            delete _inventory[j];
            _inventory[j] = NULL;
        }
    }
    if (this->_droppedItems)
    {
        while (this->_droppedItems->next)
        {
            delete (this->_droppedItems->m);
            last = this->_droppedItems;
            this->_droppedItems = this->_droppedItems->next;
            delete last;
        }
        delete (this->_droppedItems->m);
        delete (this->_droppedItems);
    }
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        std::cout << "There is only four slot in inventory [0;3]" << std::endl;
    else if (!this->_inventory[idx])
        std::cout << "This inventory slot is empty" << std::endl;
    else {
        _inventory[idx]->use(target);
        delete _inventory[idx];
        _inventory[idx] = NULL;
    }
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int j = 0; j < 4; j++)
    {
        if (this->_inventory[j])
            continue ;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (m == _inventory[i])
                {
                    std::cout << "This Materia is already equiped" << std::endl;
                    return;
                }
            }
            this->_inventory[j] = m;
            std::cout << "Item of type " << m->getType()<< " successfully equiped at index " << j << std::endl;
            m = NULL;
            return ;
        }
    }
    std::cout << "No remaining space in the inventory" << std::endl;
}

void Character::unequip(int idx)
{
    unequiped *current;
    unequiped *last;

    if (idx > 3 || idx < 0 || !this->_inventory[idx]) {
        std::cout << "Nothing to unequip in this space of inventory" << std::endl;
        return ;
    }
    current = new unequiped;
    if (!this->_droppedItems)
        this->_droppedItems = current;
    else
    {
        last = this->_droppedItems;
        while (last->next)
            last = last->next;
        last->next = current;
    }
    current->m = this->_inventory[idx];
    current->next = NULL;
    this->_inventory[idx] = NULL;
    std::cout << "Item at index " << idx << " successfully dropped!" << std::endl;
}

AMateria *Character::get_inventory_slot(int idx) const
{
    return (this->_inventory[idx]);
}