#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& Other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& Other);
    ~PresidentialPardonForm();

    PresidentialPardonForm(std::string target);

    void action(Bureaucrat const & executor) const;
    std::string getTarget() const;

private:
    std::string     _target;
};

#endif