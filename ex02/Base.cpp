#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void){
    switch (std::rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        default:
            return new C;
    }
}

void identify(Base* p)
{
    std::cout << "Element is of type :";
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Element is of type :";
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e){
        ;
    }
    try{
            B b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            return;
    }
    catch (const std::exception &e){
        ;
    }
    try{
            C c = dynamic_cast<C&>(p);
            std::cout << "C" << std::endl;
            return;
    }
    catch (const std::exception &e){
        ;
    }
}