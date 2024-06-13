#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form{
public:
    Form();
    Form(const Form& Other);
    Form& operator=(const Form& Other);
    ~Form();

    Form(std::string formName, int reqSignGrade, int reqExecGrade);

    std::string     getName() const;
    bool            getSigned() const;
    int             getSignGrade() const;
    int             getExecGrade() const;
    void            beSigned(const Bureaucrat& brc);

    class   GradeTooHighException;
    class   GradeTooLowException;

private:
    const std::string   _name;
    bool                _signed;
    const int           _reqSignGrade;
    const int           _reqExecGrade;
};

class Form::GradeTooHighException : public std::exception
{
public:
    const char * what() const throw()
    {
        return ("Error, grade too high, maximum grade is 1");
    };
};

class Form::GradeTooLowException : public std::exception
{
public:
    const char * what() const throw()
    {
        return ("Error, grade too low");
    };
};


std::ostream&   operator<<(std::ostream& Os, const Form& form);

#endif