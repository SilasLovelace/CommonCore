
#include "Fixed.hpp"

int main() {

    Fixed a;
    std::cout << "a: " << a << std::endl;

    Fixed b(5.05f);
    Fixed c(2);
    std::cout << "b = 5.05f , c = 2 " << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    std::cout << "b + c: " << (b + c) << std::endl;
    std::cout << "b - c: " << (b - c) << std::endl;
    std::cout << "b * c: " << (b * c) << std::endl;
    std::cout << "b / c: " << (b / c) << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "(++a): " << ++a << std::endl;
    std::cout << "a after (++a): " << a << std::endl;
    std::cout << "(a++): " << a++ << std::endl;
    std::cout << "a after (a++): " << a << std::endl;

    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b == c: " << (b == c) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    std::cout << "b = c: " << std::endl;
    b = c;
    std::cout << "b != c: " << (b != c) << std::endl;
    std::cout << "b == c: " << (b == c) << std::endl;

    std::cout << "d = 10.05f , e = 7.2f " << std::endl;
    const Fixed d(10.5f);
    const Fixed e(7.2f);

    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;

    std::cout << "f = (Fixed(5.05f) * Fixed(2))" << std::endl;
    Fixed const f(Fixed(5.05f) * Fixed(2));
    std::cout << f << std::endl;
    std::cout << "Max a and f: " << Fixed::max(a, f) << std::endl;

    return 0;
}