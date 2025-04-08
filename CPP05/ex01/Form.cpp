#include "Form.hpp"

Form::Form(): name("Default Form"), isSigned(false), signGrade(150), executeGrade(150) {
    // std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    // std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const &rhs) : name(rhs.getName()), isSigned(rhs.getIsSigned()), signGrade(rhs.getSignGrade()), executeGrade(rhs.getExecuteGrade()) {
    // std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(Form const &rhs) {
    if (this == &rhs)
        return *this;
    this->isSigned = rhs.getIsSigned();
    // std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}
Form::~Form() {
    // std::cout << "Form destructor called" << std::endl;
}
std::string Form::getName() const {
    return this->name;
}
bool Form::getIsSigned() const {
    return this->isSigned;
}
int Form::getSignGrade() const {
    return this->signGrade;
}
int Form::getExecuteGrade() const {
    return this->executeGrade;
}
void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade)
        throw Form::GradeTooLowException();
    else if (this->isSigned)
        throw Form::AlreadySignedException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}
const char* Form::AlreadySignedException::what() const throw() {
    return "Form already signed";
}

std::ostream& operator<<(std::ostream& os, Form const &rhs) {
    os << "Form name: " << rhs.getName() << " Is signed: " << (rhs.getIsSigned() ? "Yes" : "No") << " Sign grade: " << rhs.getSignGrade() << " Execute grade: " << rhs.getExecuteGrade() << std::endl;
    return os;
}