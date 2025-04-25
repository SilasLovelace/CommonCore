#include "Span.hpp"

Span::Span() : _max_size(0) {}
Span::Span(unsigned int n) : _max_size(n) {}
Span::Span(const Span &other) : _max_size(other._max_size), _vector(other._vector) {}
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _max_size = other._max_size;
        _vector = other._vector;
    }
    return *this;
}
Span::~Span() {}
void Span::addNumber(const int number) {
    if (_vector.size() >= _max_size) {
        throw std::out_of_range("Vector is full");
    }
    _vector.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_vector.size() < 2) {
        throw std::logic_error("Less than 2 elements in the vector");
    }
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    unsigned int min_span = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

unsigned int Span::longestSpan() const {
    if (_vector.size() < 2) {
        throw std::logic_error("Less than 2 elements in the vector");
    }
    int min = *std::min_element(_vector.begin(), _vector.end());
    int max = *std::max_element(_vector.begin(), _vector.end());
    return static_cast<unsigned int>(max - min);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _vector.size() > _max_size) {
        throw std::out_of_range("Not enough space in the vector");
    }
    _vector.insert(_vector.end(), begin, end);
}
