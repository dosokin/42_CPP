#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm{
public:
    AForm();
    AForm(const AForm& Other);
    AForm& operator=(const AForm& Other);
    ~AForm();

    AForm(std::string formName, int reqSignGrade, int reqExecGrade);

    class GradeTooHighException;
    class GradeTooLowException;
    class UnsignedForm;

    std::string     getName() const;
    bool            getSigned() const;
    int             getSignGrade() const;
    int             getExecGrade() const;
    void            beSigned(const Bureaucrat& brc);

    void    execute(Bureaucrat const & executor) const;
    virtual void action(Bureaucrat const & executor) const = 0;

private:
    const std::string   _name;
    bool                _signed;
    const int           _reqSignGrade;
    const int           _reqExecGrade;
};


class AForm::GradeTooHighException : public std::exception
{
public:
    const char * what() const throw()
    {
        return ("Error, grade too high, maximum grade is 1");
    };
};

class AForm::GradeTooLowException : public std::exception
{
public:
    const char * what() const throw() {
        return ("Error, grade too low");
    };
};

class AForm::UnsignedForm : public std::exception
{
public:
    const char * what() const throw() {
        return ("Form cant be executed as its not signed yet");
    }
};

std::ostream&   operator<<(std::ostream& Os, const AForm& form);

#endif