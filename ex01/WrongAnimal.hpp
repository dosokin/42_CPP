#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string         getType() const;
    void       makeSound() const;

protected:
    std::string type;
};


#endif
