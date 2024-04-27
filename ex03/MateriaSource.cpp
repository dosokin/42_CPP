#include "MateriaSource.hpp"
#include "AMateria.hpp"
MateriaSource::MateriaSource(){
    this->_inventory[0] = NULL;
    this->_inventory[1] = NULL;
    this->_inventory[2] = NULL;
    this->_inventory[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& Other)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (Other._inventory[i])
        {
            this->_inventory[i] = Other.get_inventory(i)->clone();
        }
    }
}

AMateria *MateriaSource::get_inventory(size_t idx) const
{
    return (this->_inventory[idx]);
}

#include <iostream>

MateriaSource    &MateriaSource::operator=(const MateriaSource& Other)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (Other._inventory[i])
        {
            this->_inventory[i] = Other.get_inventory(i)->clone();
        }
        else
            this->_inventory[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource(){
    for (int j = 0; j < 4; j++)
    {
        if (this->_inventory[j])
            delete _inventory[j];
    }
}

void MateriaSource::learnMateria(AMateria *am){
    for (size_t i = 0; i < 4; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = am;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (size_t i = 0; i < 4; i++)
    {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
        {
            return (this->_inventory[i]->clone());
        }
    }
    std::cout << "Materia not learned yet!" << std::endl;
    return (0);
}