#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(RobotomyRequestForm const &rhs);
        RobotomyRequestForm& operator=(RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

#endif