#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class AAnimal
{
public:
    std::string         getType() const;
    virtual void       makeSound() const = 0;
    virtual ~AAnimal();
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);

protected:
    std::string type;
};


#endif
