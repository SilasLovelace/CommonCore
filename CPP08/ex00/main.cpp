#include    "easyfind.hpp"
#include    <iostream>
#include    <vector>

int main (void)
{
    std::vector<int> v;
    std::vector<int>::iterator it; 
    std::vector<int>::const_iterator cit;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    std::cout << *easyfind(v, 8) << std::endl;

    try {
        std::cout << *easyfind(v, 42) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}