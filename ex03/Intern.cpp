#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& Other)
{
    (void)Other;
}

Intern& Intern::operator=(const Intern& Other)
{
    (void)Other;
    return (*this);
}

Intern::~Intern()
{}


AForm* Intern::makeForm(std::string type, std::string target)
{
    AForm *Form;
    static const std::string table[]= {
            "shrubbery", "robotomy", "presidential", "SHRUBBERY", "ROBOTOMY", "PRESIDENTIAL", "shrubbery form", "robotomy form", "presidential form", "SHRUBBERY FORM", "ROBOTOMY FORM", "PRESIDENTIAL FORM"
    };
    for (size_t i = 0; i < 12; i++)
    {
        if (type == table[i])
        {
            switch (i % 3)
            {
                case (0) :
                {
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    return (Form = new ShrubberyCreationForm(target));
                }
                case (1) :
                {
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    return (Form = new RobotomyRequestForm(target));
                }
                case (2) :
                {
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                    return (Form = new PresidentialPardonForm(target));
                }
            }
        }
    }
    std::cout << "Form type doesnt exist" << std::endl;
    return (NULL);
}