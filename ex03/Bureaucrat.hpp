#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& Other);
    Bureaucrat& operator=(const Bureaucrat& Other);
    ~Bureaucrat();

    Bureaucrat(std::string name, int grade);

    std::string     getName() const;
    int    getGrade() const;

    void    incrementGrade();
    void    decrementGrade();
    class   GradeTooHighException;
    class   GradeTooLowException;

    void    signForm(AForm& form) const;
    void    executeForm(AForm const & form) const;
private:
    const std::string   _name;
    int        _grade;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
    const char * what() const throw()
    {
        return ("Error, grade too high");
    };
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
    const char * what() const throw()
    {
        return ("Error, grade too low");
    };
};

std::ostream&    operator<<(std::ostream& Os, const Bureaucrat& brc);

#endif