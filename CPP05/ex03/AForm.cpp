#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default AForm"), isSigned(false), signGrade(150), executeGrade(150) {
    // std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty");
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    // std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const &rhs) : name(rhs.getName()), isSigned(rhs.getIsSigned()), signGrade(rhs.getSignGrade()), executeGrade(rhs.getExecuteGrade()) {
    // std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(AForm const &rhs) {
    if (this == &rhs)
        return *this;
    this->isSigned = rhs.getIsSigned();
    // std::cout << "AForm copy assignment operator called" << std::endl;
    return *this;
}
AForm::~AForm() {
    // std::cout << "AForm destructor called" << std::endl;
}
std::string AForm::getName() const {
    return this->name;
}
bool AForm::getIsSigned() const {
    return this->isSigned;
}
int AForm::getSignGrade() const {
    return this->signGrade;
}
int AForm::getExecuteGrade() const {
    return this->executeGrade;
}
void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->signGrade)
        throw AForm::GradeTooLowException();
    else if (this->isSigned)
        throw AForm::AlreadySignedException();
    std::cout << bureaucrat.getName() << " signed " << this->name << std::endl;
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!this->isSigned)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->executeGrade)
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " executed " << this->name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}
const char* AForm::AlreadySignedException::what() const throw() {
    return "AForm already signed";
}
const char* AForm::NotSignedException::what() const throw() {
    return "AForm not signed";
}

std::ostream& operator<<(std::ostream& os, AForm const &rhs) {
    os << "AForm name: " << rhs.getName() << " Is signed: " << (rhs.getIsSigned() ? "Yes" : "No") << " Sign grade: " << rhs.getSignGrade() << " Execute grade: " << rhs.getExecuteGrade() << std::endl;
    return os;
}