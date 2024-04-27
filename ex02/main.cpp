#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main() {
    //const AAnimal *justAnAnimal = new AAnimal();
    const AAnimal *realDog = new Dog();
    const AAnimal *realCat = new Cat();

    std::cout << "\nSound of a ";
    std::cout << realDog->getType() << " is: ";
    realDog->makeSound();
    std::cout << "\n" << std::endl;

    std::cout << "Sound of a ";
    std::cout << realCat->getType() << " is: ";
    realCat->makeSound();
    std::cout << "\n" << std::endl;

//    std::cout << "Sound of an ";
//    std::cout << justAnAnimal->getType() << " is: ";
//    justAnAnimal->makeSound();
//    std::cout << "\n" << std::endl;

    //delete justAnAnimal;
    delete realDog;
    delete realCat;
    return 0;
}