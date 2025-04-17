#include "ScalarConverter.hpp"

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define INVALID 4


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
    if (str.length() == 1 && std::isalpha(str[0]))
        return CHAR;
    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        return DOUBLE;
    if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        return FLOAT;
    size_t i;
    if ((str[0] == '-' || str[0] == '+') && str.length() > 1)
        i = 1;
    else
        i = 0;
        
    if (std::isdigit(str[i]))
    {
        for (; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
                break;
        }
        if (i == str.length())
            return INT;
    }
    size_t dot = str.find('.');
    if (dot != std::string::npos)
    {
        bool valid = true;
        for (i = ((str[0] == '-' || str[0] == '+') ? 1 : 0); i < dot; i++)
        {
            if (!std::isdigit(str[i]))
            {
                valid = false;
                break;
            }
        }
        if (valid && dot < str.length() - 1)
        {
            for (size_t i = dot + 1; i < str.length(); i++)
            {
                if (!std::isdigit(str[i]))
                {
                    if (str[i] == 'f' && i == str.length() - 1)
                        return FLOAT;
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid)
                return DOUBLE;
        }
    }
    return INVALID;
}

void ScalarConverter::convert(std::string str)
{
    char type = stringparser(str);
    
    bool isNan = (str == "nan" || str == "nanf");
    bool isInf = (str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || 
                 str == "-inf" || str == "-inff");
    char c;
    int i;
    float f;
    double d;

    if (type == CHAR)
    {
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (type == INT)
    {
        try{
            i = std::stoi(str);
        }catch (std::out_of_range &e){
            std::cout << "overflow of int input conversions not executed" << std::endl;
            return;
        }
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (type == FLOAT)
    {
        try{
            f = std::stof(str);
        }catch (std::out_of_range &e){
            std::cout << "overflow of float input conversions not executed" << std::endl;
            return;
        }
        if (!isNan && !isInf) {
            c = static_cast<char>(f);
            i = static_cast<int>(f);
        }
        d = static_cast<double>(f);
    }
    else if (type == DOUBLE)
    {
        try{
            d = std::stod(str);
        }catch (std::out_of_range &e){
            std::cout << "overflow of double input conversions not executed" << std::endl;
            return;
        }
        if (!isNan && !isInf) {
            c = static_cast<char>(d);
            i = static_cast<int>(d);
        }
        f = static_cast<float>(d);
    }
    else {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (isNan || isInf)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (isNan || isInf)
        std::cout << "impossible" << std::endl;
    else
    {
        if (d > (double)std::numeric_limits<int>::max() || d < (double)std::numeric_limits<int>::min() \
            || f > (float)std::numeric_limits<int>::max() || f < (float)std::numeric_limits<int>::min())
            std::cout << "impossible because input would overflow int value" << std::endl;
        else
            std::cout << i << std::endl;
    }
    
    std::cout << "float: ";
    if (isNan)
        std::cout << "nanf" << std::endl;
    else if (isInf) {
        if (str[0] == '-')
            std::cout << "-inff" << std::endl;
        else
            std::cout << "inff" << std::endl;
    }
    else {

        if (d > (double)std::numeric_limits<float>::max() || d < (double)std::numeric_limits<float>::min())
            std::cout << "impossible because input would overflow float value" << std::endl;
        else
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << f << "f";
            std::cout << oss.str() << std::endl;
        }
    }
    
    std::cout << "double: ";
    if (isNan)
        std::cout << "nan" << std::endl;
    else if (isInf) {
        if (str[0] == '-')
            std::cout << "-inf" << std::endl;
        else
            std::cout << "inf" << std::endl;
    }
    else {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << d;
        std::cout << oss.str() << std::endl;
    }
}