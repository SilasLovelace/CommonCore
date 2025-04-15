#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs), target(rhs.target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    if (this != &rhs) {
        this->AForm::operator=(rhs);
    }
    return *this;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    try {
        this->AForm::execute(executor);
    } catch (std::exception &e) {
        throw ;
    }
    std::ofstream file(target + "_shrubbery");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << target + "_shrubbery" << std::endl;
        return;
    }
    file << "       _-_-_\n";
    file << "    _-_-_-_-_\n";
    file << " _-_-_-_-_-_-_\n";
    file << "  -_-_-_-_-_-_\n";
    for (int i = 0; i < 100000; ++i) {
        file << "       | \n";
    }
    file << "Congratulations! your reached the end of the Tree!\n";
    std::cout << "Shrubbery created in file " << target + "_shrubbery" << std::endl;
    file.close();
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}