#include "Base.hpp"
#include <random>

int main ()
{
    srand(time(0));
    Base *base = generate();
    identify(base);
    try {
        identify(*base);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    
    }
    delete base;
    return 0;
}