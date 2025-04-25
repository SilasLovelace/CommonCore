#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){}
Base::~Base(){}
Base *generate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch (std::bad_cast &e) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch (std::bad_cast &e) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch (std::bad_cast &e) {}
}