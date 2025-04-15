#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("Default") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm(rhs), target(rhs.target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    if (this != &rhs) {
        this->AForm::operator=(rhs);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    try {
        this->AForm::execute(executor);
    } catch (std::exception &e) {
        throw ;
    }
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << target << " robotomy failed!" << std::endl;
    }
}