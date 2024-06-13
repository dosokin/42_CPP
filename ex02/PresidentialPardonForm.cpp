#include <iostream>
#include <cstdlib>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& Other) : AForm(Other), _target(Other.getTarget())
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& Other)
{
    this->_target = Other.getTarget();
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{}

std::string PresidentialPardonForm::getTarget() const{
    return (this->_target);
}


void PresidentialPardonForm::action(Bureaucrat const & executor) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox by " << executor.getName() << std::endl;
    return ;
}