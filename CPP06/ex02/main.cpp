#include "Base.hpp"
#include <random>

int main ()
{
    srand(time(0));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}