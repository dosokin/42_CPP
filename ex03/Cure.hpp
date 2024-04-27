#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{
public:
    Cure();
    Cure(const Cure& Other);
    Cure& operator=(const Cure& Other);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
