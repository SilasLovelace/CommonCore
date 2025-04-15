#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    private:
        typedef AForm* (Intern::*Function)(const std::string&);
        std::string formNames[3];
        Function formFunctions[3];
    public:
        Intern();
        Intern(Intern const &rhs);
        Intern& operator=(Intern const &rhs);
        ~Intern();

        AForm* makeForm(const std::string& formName,const std::string& target);
        AForm* makePresidentialPardonForm(const std::string& target);
        AForm* makeRobotomyRequestForm(const std::string& target);
        AForm* makeShrubberyCreationForm(const std::string& target);
        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
#endif