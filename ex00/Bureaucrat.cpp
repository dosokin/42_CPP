#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    throw (std::logic_error("A Bureaucrat couldnt be created w/o specified grade"));
}

Bureaucrat::Bureaucrat(const Bureaucrat& Other) : _name(Other.getName()), _grade(Other.getGrade())
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& Other)
{
    this->_grade = Other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}


std::string     Bureaucrat::getName() const
{
    return (this->_name);
}

int    Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade() {
    if (this->_grade == 1)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade--;
}

void    Bureaucrat::decrementGrade() {
    if (this->_grade == 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade++;
}

std::ostream&    operator<<(std::ostream& Os, const Bureaucrat& brc)
{
    Os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
    return (Os);
}