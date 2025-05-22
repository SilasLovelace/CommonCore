#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

int my_stoi (std::string token)
{
    int num = 0;
    for (std::basic_string<char>::size_type i = 0; i < token.size(); ++i)
    {
        num = num * 10 + (token[i] - '0');
        if (num < 0)
        {
            throw std::invalid_argument("Overflow of: " + token);
            break;
        }
    }
    return num;
}
void RPN::execute(const std::string &inputStr)
{
    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token)
    {
        if (token.empty() || token.find_first_not_of("0123456789+-*/") != std::string::npos || token.size() > 1)
            throw std::invalid_argument("Invalid Input: " + token);
        else{
                if (token == "+" || token == "-" || token == "*" || token == "/")
                {
                    if (_stack.size() < 2)
                        throw std::runtime_error("Error: too many operands");
                    double b = _stack.top();
                    _stack.pop();
                    double a = _stack.top();
                    _stack.pop();
                    if (token == "+")
                        _stack.push(a + b);
                    else if (token == "-")
                        _stack.push(a - b);
                    else if (token == "*")
                        _stack.push(a * b);
                    else if (token == "/")
                    {
                        if (b == 0)
                            throw std::runtime_error("Error: Division by zero");
                        _stack.push(a / b);
                    }
                    if (_stack.top() > 2147483647 || _stack.top() < -2147483648)
                        throw std::runtime_error("Error: Overflow of int");
                }
                else
                {
                    double num = my_stoi(token);
                    _stack.push(num);
                }
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Not enough operands");
    std::cout << "Result: " << static_cast<int>(_stack.top()) << std::endl;
}