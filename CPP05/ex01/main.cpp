#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    
    try {
        Form form_B("Form B", 150, 151);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form_B("Form B", 0, 150);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat bureaucrat_A("Bureacraty A.", 1);
    Form form_A("Form A", 1, 1);
    Bureaucrat bureaucrat_B("Baurucrot B.", 150);
    Form form_B("Form B", 150, 149);
    Form form_C("Form C", 149, 149);

    bureaucrat_B.signForm(form_A);
    bureaucrat_B.signForm(form_B);
    bureaucrat_B.signForm(form_C);
    bureaucrat_B.incrementGrade();
    bureaucrat_B.signForm(form_C);
    bureaucrat_A.signForm(form_A);
    bureaucrat_A.signForm(form_A);
    return 0;
}