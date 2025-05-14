#ifndef PRN_HPP
#define PRN_HPP
#include <iostream>
#include <stack>
#include <sstream>

class RPN{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();
        void execute(const std::string &inputStr);
};

#endif