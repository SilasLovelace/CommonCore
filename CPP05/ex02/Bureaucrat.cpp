#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Mark S."), grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
    std::cout << "Constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : name(rhs.getName()) {
    this->grade = rhs.getGrade();
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this == &rhs)
        return *this;
    this->grade = rhs.getGrade();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs) {
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return os;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}
int Bureaucrat::getGrade() const {
    return this->grade;
}
const std::string Bureaucrat::getName() const {
    return this->name;
}
void Bureaucrat::incrementGrade() {
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}
void Bureaucrat::decrementGrade() {
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}