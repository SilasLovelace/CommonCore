#include    "iter.hpp"
#include    <iostream>

void multiply(int& n)
{
    n *= 2;
}

template <typename T>
void print(T& value) {
    std::cout << value << " ";
}

int main (void)
{
    int arr[] = {1, 2, 3, 4};
    std::cout << "Before: ";
    iter (arr, 4, print<int>);
    iter(arr, 4, multiply);
    std::cout << "\nAfter: ";
    for (int i = 0; i < 4; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}