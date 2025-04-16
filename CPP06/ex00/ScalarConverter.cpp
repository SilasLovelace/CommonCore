#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {}
    return *this;
}

char stringparser(std::string str)
{
    int i = 0;
    if (str.length() == 1 && std::isalpha(str[0]))
        return CHAR;
    if ((str[0] == '-' && str.length() > 1) || std::isdigit(str[0]))
    {
        int int_flag = 0;
        for (i = (std::isdigit(str[0]) ? 0 : 1); i < (int)str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                int_flag =  1;
                break;
            }
        }
        if (int_flag == 0 && i == (int)str.length() - 1)
            return INT;
    }
    if (str[i] == '.' && i < (int)str.length() && std::isdigit(str[i + 1]))
    {
        int double_flag = 0;
        while(i++ < (int)str.length())
        {
            if (!isdigit(str[i]))
            {
                double_flag = 1;
                break;
            }
        }
        if (double_flag == 0 && i == (int)str.length() - 1)
            return DOUBLE;
    }
    //only numbers then dot then only numbers then an f then end 
    //enum for static convert to protet againts overflow
    // else if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
    //     return FLOAT;
    return INVALID;
}

void ScalarConverter::convert(std::string str)
{
    char type = stringparser(str);
    switch (type)
    {
        case CHAR:
            std::cout << "char: " << str[0] << std::endl;
            break;
        case INT:
            std::cout << "int: " << std::stoi(str) << std::endl;
            break;
        case DOUBLE:
            std::cout << "double: " << std::stod(str) << std::endl;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}