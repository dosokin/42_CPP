#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 145);
        std::cout << lowLevelBureaucrat << std::endl;
        Form lowLevelForm = Form("LowLevelForm", 50, 145);
        std::cout << lowLevelForm << std::endl;
        lowLevelBureaucrat.signForm(lowLevelForm);
        std::cout << lowLevelForm << std::endl;
        //lowLevelForm.beSigned(lowLevelBureaucrat);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

//    try {
//        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 145);
//        std::cout << lowLevelBureaucrat << std::endl;
//        Form midLevelForm = Form("MidLevelForm", 70, 50);
//        std::cout << midLevelForm << std::endl;
//        midLevelForm.beSigned(lowLevelBureaucrat);
//        std::cout << midLevelForm << std::endl;
//    }
//    catch (std::exception& e){
//        std::cout << e.what() << std::endl;
//    }
//    std::cout << std::endl;
//
//    try {
//        Bureaucrat lowLevelBureaucrat = Bureaucrat("LowLevelBureaucrat", 145);
//        std::cout << lowLevelBureaucrat << std::endl;
//        Form midLevelForm = Form("MidLevelForm", 70, 50);
//        for (;lowLevelBureaucrat.getGrade() > 70;)
//            lowLevelBureaucrat.incrementGrade();
//        std::cout << midLevelForm << std::endl;
//        midLevelForm.beSigned(lowLevelBureaucrat);
//        std::cout << midLevelForm << std::endl;
//    }
//    catch (std::exception& e){
//        std::cout << e.what() << std::endl;
//    }

    return (0);
}