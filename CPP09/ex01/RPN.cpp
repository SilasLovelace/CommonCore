#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

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
                    switch (token[0])
                    {
                        case '+':
                            _stack.push(a + b);
                            break;
                        case '-':
                            _stack.push(a - b);
                            break;
                        case '*':
                            _stack.push(a * b);
                            break;
                        case '/':
                            if (b == 0)
                                throw std::runtime_error("Error: Division by zero");
                            _stack.push(a / b);
                            break;
                        default:
                            throw std::invalid_argument("Invalid operator: " + token);
                    }

                }
                else
                {
                    double num = std::atoi(token.c_str());
                    _stack.push(num);
                }
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Not enough operands");
    std::cout << "Result: " << _stack.top() << std::endl;
}