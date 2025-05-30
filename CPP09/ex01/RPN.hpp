#ifndef PRN_HPP
#define PRN_HPP
#include <iostream>
#include <stack>
#include <list>
#include <sstream>
#include <string>
#include <cstdlib>


class RPN{
    private:
        std::stack<double, std::list<double> > _stack;
        RPN &operator=(const RPN &src);
        RPN(const RPN &src);
    public:
        RPN();
        ~RPN();
        void execute(const std::string &inputStr);
};

#endif