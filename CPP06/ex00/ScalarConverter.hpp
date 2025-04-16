#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define INVALID 4

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