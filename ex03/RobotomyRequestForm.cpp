#include <iostream>
#include <cstdlib>
#include <time.h>

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Other) : AForm(Other), _target(Other.getTarget())
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& Other)
{
    this->_target = Other.getTarget();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyReq", 72, 45), _target(target)
{}

std::string RobotomyRequestForm::getTarget() const{
    return (this->_target);
}


void RobotomyRequestForm::action(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw (AForm::UnsignedForm());
    if (this->getExecGrade() < executor.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    std::cout << "brzzzzzz zzdzbzbb z bbzbzb *drill noise you get it*" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->_target << " get successfully robotomised by " << executor.getName() << std::endl;
    else
        std::cout << "Robotomisation of " << this->_target << " failed" << std::endl;
    return ;
}