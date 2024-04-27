#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"


int main() {

    Animal  *array[20];

    for (size_t i = 0; i < 20; i++)
    {
        if (i < 10)
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }
    for (size_t i = 0; i < 20; i++)
        delete array[i];
}