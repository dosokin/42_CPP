#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 140);
        Bureaucrat midLevelBureaucrat = Bureaucrat("MidLevelBureaucrat", 75);
        Bureaucrat highLevelBureaucrat = Bureaucrat("HighLevelBureaucrat", 10);
        Bureaucrat president = Bureaucrat("President", 1);
        ShrubberyCreationForm shrubbery("target");
        try{
            std::cout << lowLevelBureaucrat << std::endl;
            std::cout << shrubbery << std::endl;
            lowLevelBureaucrat.signForm(shrubbery);
            std::cout << shrubbery << std::endl;
            shrubbery.execute(lowLevelBureaucrat);
        }
        catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        try{
            std::cout << midLevelBureaucrat << std::endl;
            std::cout << shrubbery << std::endl;
            shrubbery.execute(midLevelBureaucrat);
        }
        catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
//    try {
//        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 140);
//        Bureaucrat midLevelBureaucrat = Bureaucrat("MidLevelBureaucrat", 75);
//        Bureaucrat highLevelBureaucrat = Bureaucrat("HighLevelBureaucrat", 10);
//        Bureaucrat president = Bureaucrat("President", 1);
//        RobotomyRequestForm robotomy("target");
//        try{
//            std::cout << midLevelBureaucrat << std::endl;
//            std::cout << robotomy << std::endl;
//            robotomy.beSigned(midLevelBureaucrat);
//            std::cout << robotomy << std::endl;
//            robotomy.execute(midLevelBureaucrat);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//        std::cout << std::endl;
//        try{
//            std::cout << highLevelBureaucrat << std::endl;
//            std::cout << robotomy << std::endl;
//            robotomy.beSigned(highLevelBureaucrat);
//            robotomy.execute(highLevelBureaucrat);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//    }
//    catch (std::exception& e){
//        std::cout << e.what() << std::endl;
//    }
//    std::cout << std::endl;
//    try {
//        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 140);
//        Bureaucrat midLevelBureaucrat = Bureaucrat("MidLevelBureaucrat", 75);
//        Bureaucrat highLevelBureaucrat = Bureaucrat("HighLevelBureaucrat", 10);
//        Bureaucrat president = Bureaucrat("President", 1);
//        PresidentialPardonForm presidential("target");
//        try{
//            std::cout << highLevelBureaucrat << std::endl;
//            std::cout << presidential << std::endl;
//            presidential.beSigned(highLevelBureaucrat);
//            std::cout << presidential << std::endl;
//            presidential.execute(highLevelBureaucrat);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//        std::cout << std::endl;
//        try{
//            std::cout << president << std::endl;
//            std::cout << presidential << std::endl;
//            presidential.beSigned(president);
//            presidential.execute(president);
//        }
//        catch (std::exception& e){
//            std::cout << e.what() << std::endl;
//        }
//    }
//    catch (std::exception& e){
//        std::cout << e.what() << std::endl;
//    }
    return (0);
}