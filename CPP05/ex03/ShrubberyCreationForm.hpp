#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

#endif