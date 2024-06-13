#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _reqSignGrade(0), _reqExecGrade(0)
{
    throw (std::logic_error("A Form couldnt be created w/o mandatories infos"));
}

AForm::AForm(const AForm& Other) : _name(Other.getName()), _signed(Other.getSigned()), _reqSignGrade(Other.getSignGrade()), _reqExecGrade(Other.getExecGrade())
{}

AForm& AForm::operator=(const AForm& Other)
{
    (void)Other;
    throw (std::logic_error("A Form is intangible, so cant be fully crushed"));
}

AForm::~AForm()
{}

AForm::AForm(std::string formName, int reqSignGrade, int reqExecGrade) : _name(formName), _signed(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade)
{
    if (this->_reqSignGrade < 1 || this->_reqExecGrade < 1)
        throw (AForm::GradeTooHighException());
    if (this->_reqSignGrade > 150 || this->_reqExecGrade > 150)
        throw (AForm::GradeTooLowException());
}


std::string     AForm::getName() const{
    return(this->_name);
}

bool            AForm::getSigned() const{
    return(this->_signed);
}

int             AForm::getSignGrade() const{
    return(this->_reqSignGrade);
}

int             AForm::getExecGrade() const{
    return(this->_reqExecGrade);
}

std::ostream&   operator<<(std::ostream& Os, const AForm& form)
{
    if (form.getSigned())
        Os << "Signed " << form.getName() <<  " require a minimum grade of " << form.getSignGrade() << " to be signed and a minimum grade of " << form.getExecGrade() << " to be executed";
    else
        Os << "Unsigned " << form.getName() <<  " require a minimum grade of " << form.getSignGrade() << " to be signed and a minimum grade of " << form.getExecGrade() << " to be executed";
    return (Os);
}

void            AForm::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > this->getSignGrade())
        throw (AForm::GradeTooLowException());
    this->_signed = true;
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw (AForm::UnsignedForm());
    if (this->getExecGrade() < executor.getGrade())
        throw (Bureaucrat::GradeTooLowException());
    this->action(executor);
}

