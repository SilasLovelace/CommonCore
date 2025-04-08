#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat a;
    Bureaucrat b(1);
    Bureaucrat c(150);
    try {
        Bureaucrat d(151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat e(0);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << "-------------------------" << std::endl;

    try {
        a.incrementGrade();
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b.incrementGrade();
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}