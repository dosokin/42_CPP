#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm{

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& Other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& Other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(std::string target);

    void action(Bureaucrat const & executor) const;
    std::string getTarget() const;

    std::range_error ErrorOpen() const;

private:
    std::string     _target;
};

#endif