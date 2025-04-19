#include    "Span.hpp"
#include    <iostream>
#include    <random>
int main()
{
    srand(time(0));
    std::cout << "-------basic test---------" << std::endl;
    Span sp = Span(5);
    try{
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(12);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "-------10 k test---------" << std::endl;
    std::vector<int> v(10000);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = rand();
    }
    Span sp2 = Span(10000);
    sp2.addNumber(6);
    sp2.addNumbers(v.begin(), v.end() - 1);
    try {
        sp2.addNumber(12);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
}