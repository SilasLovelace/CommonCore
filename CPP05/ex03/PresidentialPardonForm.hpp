#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm const &rhs);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &rhs);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};
#endif