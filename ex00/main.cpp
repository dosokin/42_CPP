#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main() {
    Animal          justAnAnimal;
    Dog             realDog;
    Cat             realCat;

    WrongAnimal     wrongAnimal;
    WrongCat        wrongCat;

    std::cout << "\nSound of a ";
    std::cout << realDog.getType() << " is: ";
    realDog.makeSound();
    std::cout << "\n" << std::endl;

    std::cout << "Sound of a ";
    std::cout << realCat.getType() << " is: ";
    realCat.makeSound();
    std::cout << "\n" << std::endl;

    std::cout << "Sound of an ";
    std::cout << justAnAnimal.getType() << " is: ";
    justAnAnimal.makeSound();
    std::cout << "\n" << std::endl;

    std::cout << "Sound of a ";
    std::cout << wrongAnimal.getType() << " is: ";
    wrongAnimal.makeSound();
    std::cout << "\n" << std::endl;

    std::cout << "Sound of a ";
    std::cout << wrongCat.getType() << " is: ";
    wrongCat.makeSound();
    std::cout << "\n" << std::endl;

    return 0;
}
