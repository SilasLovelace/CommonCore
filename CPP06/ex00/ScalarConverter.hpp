#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter(ScalarConverter const &rhs);
        ScalarConverter& operator=(ScalarConverter const &rhs);
        ScalarConverter();
        virtual ~ScalarConverter() = 0;
    public:
        static void convert(std::string str);
};

#endif