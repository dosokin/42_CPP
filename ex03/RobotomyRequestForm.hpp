#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& Other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& Other);
    ~RobotomyRequestForm();

    RobotomyRequestForm(std::string target);

    void action(Bureaucrat const & executor) const;
    std::string getTarget() const;

private:
    std::string     _target;
};

#endif