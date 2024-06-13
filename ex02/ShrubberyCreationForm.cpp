#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& Other) : AForm(Other), _target(Other.getTarget())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& Other)
{
    this->_target = Other.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry", 145, 137), _target(target)
{}

std::string ShrubberyCreationForm::getTarget() const{
    return (this->_target);
}

std::range_error ShrubberyCreationForm::ErrorOpen() const
{
    return (std::range_error("Error opening file"));
}

void ShrubberyCreationForm::action(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw (AForm::UnsignedForm());
    if (this->getExecGrade() < executor.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    std::ofstream Os;
    std::string file_name(this->_target + "_shrubbery");
    Os.open(file_name.c_str());
    if (!Os)
        throw (ShrubberyCreationForm::ErrorOpen());
    Os << "      _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
    Os << "      _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\";
    Os.close();
    std::cout << "Shrubbery form get successfully executed by " << executor.getName() << std::endl;
}