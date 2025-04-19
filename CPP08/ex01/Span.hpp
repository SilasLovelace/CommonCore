#ifndef SPAN_HPP
#define SPAN_HPP

// #include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits.h>

class Span {

private:
    unsigned int _max_size;
    std::vector<int> _vector;
    Span();
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
#endif