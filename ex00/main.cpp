#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat test = Bureaucrat("TooHighGrade", -5);
        std::cout << test << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat test = Bureaucrat("TooLowGrade", 467);
        std::cout << test << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

//    try {
//        Bureaucrat test = Bureaucrat();
//        std::cout << test << std::endl;
//    }
//    catch (std::exception& e){
//        std::cerr << e.what() << std::endl;
//    }
//
//    try {
//        Bureaucrat test = Bureaucrat("RightGrade", 99);
//        std::cout << test << std::endl;
//    }
//    catch (std::exception& e){
//        std::cerr << e.what() << std::endl;
//    }
//
//    try {
//        Bureaucrat test = Bureaucrat("RightGradeCopiedByRef", 88);
//        Bureaucrat copy = Bureaucrat(test);
//        std::cout << copy << std::endl;
//    }
//    catch (std::exception& e){
//        std::cerr << e.what() << std::endl;
//    }
//
//    try {
//        Bureaucrat test = Bureaucrat("RightGradeCopiedByAssignment", 77);
//        Bureaucrat copy("Tempo", 1);
//        copy = test;
//        std::cout << copy << std::endl;
//    }
//    catch (std::exception& e){
//        std::cerr << e.what() << std::endl;
//    }
//
//    try {
//        Bureaucrat test = Bureaucrat("IncrementTest", 66);
//        std::cout << test << std::endl;
//        for (size_t i = 0; i < 65; i++)
//            test.incrementGrade();
//        std::cout << test << std::endl;
//        //test.incrementGrade();
//        //std::cout << test << std::endl;
//    }
//    catch (std::exception& e) {
//        std::cerr << e.what() << std::endl;
//    }

    return (0);
}