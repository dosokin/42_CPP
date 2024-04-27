#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& Other);
    MateriaSource& operator=(const MateriaSource& Other);
    ~MateriaSource();

    AMateria *get_inventory(size_t idx) const;
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

private:
    AMateria*    _inventory[4];
};

#endif
