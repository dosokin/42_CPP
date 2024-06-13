#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern{
public:
    Intern();
    Intern(const Intern& Other);
    Intern& operator=(const Intern& Other);
    ~Intern();

    AForm *makeForm(std::string type, std::string target);
};

#endif