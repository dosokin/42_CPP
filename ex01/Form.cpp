#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _reqSignGrade(0), _reqExecGrade(0)
{
    throw (std::logic_error("A Form couldnt be created w/o infos"));
}

Form::Form(const Form& Other) : _name(Other.getName()), _signed(Other.getSigned()), _reqSignGrade(Other.getSignGrade()), _reqExecGrade(Other.getExecGrade())
{}

Form& Form::operator=(const Form& Other)
{
    (void)Other;
    throw (std::logic_error("A Form is intangible, so cant be fully crushed"));
}

Form::~Form()
{}

Form::Form(std::string formName, int reqSignGrade, int reqExecGrade) : _name(formName), _signed(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade)
{
    if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
        throw (Form::GradeTooHighException());
    if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
        throw (Form::GradeTooLowException());
}


std::string     Form::getName() const{
    return(this->_name);
}

bool            Form::getSigned() const{
    return(this->_signed);
}

int             Form::getSignGrade() const{
    return(this->_reqSignGrade);
}

int             Form::getExecGrade() const{
    return(this->_reqExecGrade);
}

std::ostream&   operator<<(std::ostream& Os, const Form& form)
{
    if (form.getSigned())
        Os << "Signed " << form.getName() <<  " require a minimum grade of " << form.getSignGrade() << " to be signed and a minimum grade of " << form.getExecGrade() << " to be executed";
    else
        Os << "Unsigned " << form.getName() <<  " require a minimum grade of " << form.getSignGrade() << " to be signed and a minimum grade of " << form.getExecGrade() << " to be executed";
    return (Os);
}

void            Form::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > this->getSignGrade())
        throw (Form::GradeTooLowException());
    this->_signed = true;
}