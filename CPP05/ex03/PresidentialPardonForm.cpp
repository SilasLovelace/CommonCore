#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), target("Default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm(rhs), target(rhs.target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    if (this != &rhs) {
        this->AForm::operator=(rhs);
    }
    return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    try {
        this->AForm::execute(executor);
    } catch (std::exception &e) {
        throw ;
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {}