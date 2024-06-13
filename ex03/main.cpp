#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
    Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 140);
    Bureaucrat midLevelBureaucrat = Bureaucrat("MidLevelBureaucrat", 75);
    Bureaucrat highLevelBureaucrat = Bureaucrat("HighLevelBureaucrat", 10);
    Bureaucrat president = Bureaucrat("President", 1);
    Intern intern;

    AForm *shrubbery = intern.makeForm("shrubbery form", "target");
    try {
        try{
            std::cout << lowLevelBureaucrat << std::endl;
            std::cout << *shrubbery << std::endl;
            shrubbery->beSigned(lowLevelBureaucrat);
            std::cout << *shrubbery << std::endl;
            shrubbery->execute(lowLevelBureaucrat);
        }
        catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        try{
            std::cout << midLevelBureaucrat << std::endl;
            std::cout << *shrubbery << std::endl;
            shrubbery->execute(midLevelBureaucrat);
        }
        catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    delete shrubbery;
    std::cout << std::endl;
//    AForm *robotomy = intern.makeForm("robotomy form", "target");
//    try {
//        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 140);
//        Bureaucrat midLevelBureaucrat = Bureaucrat("MidLevelBureaucrat", 75);
//        Bureaucrat highLevelBureaucrat = Bureaucrat("HighLevelBureaucrat", 10);
//        Bureaucrat president = Bureaucrat("President", 1);
//
//        try{
//            std::cout << midLevelBureaucrat << std::endl;
//            std::cout << robotomy << std::endl;
//            robotomy->beSigned(midLevelBureaucrat);
//            std::cout << robotomy << std::endl;
//            robotomy->execute(midLevelBureaucrat);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//        std::cout << std::endl;
//        try{
//            std::cout << highLevelBureaucrat << std::endl;
//            std::cout << robotomy << std::endl;
//            robotomy->beSigned(highLevelBureaucrat);
//            robotomy->execute(highLevelBureaucrat);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//    }
//    catch (std::exception& e){
//        std::cout << e.what() << std::endl;
//    }
//    delete robotomy;
//    std::cout << std::endl;
//    return (0);
}