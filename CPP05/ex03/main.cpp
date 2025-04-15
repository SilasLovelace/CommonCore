#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main(void){
    srand(time(NULL));
    Bureaucrat b_high("Bureaucrat_high", 1);
    Bureaucrat b_low("Bureaucrat_low", 150);
    ShrubberyCreationForm S_Form = ShrubberyCreationForm("my home");
    PresidentialPardonForm P_Form = PresidentialPardonForm("Your Mom");
    RobotomyRequestForm R_Form = RobotomyRequestForm("Your Dad");

    b_high.executeForm(S_Form);
    b_low.executeForm(S_Form);
    std::cout << "-----------------------" << std::endl;
    b_low.signForm(S_Form);
    b_high.signForm(S_Form);
    b_high.signForm(P_Form);
    b_high.signForm(R_Form);
    std::cout << "-----------------------" << std::endl;
    b_low.executeForm(S_Form);
    b_high.executeForm(S_Form);
    b_high.executeForm(P_Form);
    b_high.executeForm(R_Form);
    b_high.executeForm(R_Form);
    b_high.executeForm(R_Form);
    b_high.executeForm(R_Form);

    Intern someRandomIntern;

    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    delete rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    delete rrf;
    try {
        rrf = someRandomIntern.makeForm("blub", "Bender");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}