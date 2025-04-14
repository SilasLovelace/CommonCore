#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int executeGrade;

    public:
        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(AForm const &rhs);
        AForm& operator=(AForm const &rhs);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        virtual void beSigned(Bureaucrat &bureaucrat) = 0;

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

        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const &rhs);
#endif