#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &rhs);
        Bureaucrat& operator=(Bureaucrat const &rhs);
        ~Bureaucrat();

        int getGrade() const;
        const std::string getName() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs);

#endif