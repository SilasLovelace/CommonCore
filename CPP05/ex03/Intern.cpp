#include "Intern.hpp"
#include "AForm.hpp"

AForm *Intern::makePresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm *Intern::makeShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

Intern::Intern() {
    formNames[0] = "presidential pardon";
    formNames[1] = "robotomy request";
    formNames[2] = "shrubbery creation";

    formFunctions[0] = &Intern::makePresidentialPardonForm;
    formFunctions[1] = &Intern::makeRobotomyRequestForm;
    formFunctions[2] = &Intern::makeShrubberyCreationForm;
}
Intern& Intern::operator=(Intern const &rhs) {
    if (this == &rhs)
    return *this;
return *this;
}
Intern::Intern(Intern const &rhs) {
    *this = rhs;
}
Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Formtype does not exist!";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return (this->*formFunctions[i])(target);
        }
    }
    throw FormNotFoundException();
}