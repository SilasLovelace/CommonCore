#include    "Array.hpp"
#include    <iostream>
#include    <cstdlib>

template <typename T>
void print(Array<T> &arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main (void)
{
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.size(); i++)
        intArray[i] = i ;
    Array<int> intArray2(intArray);
    print<int>(intArray);
    print<int>(intArray2);
    for (size_t i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;
    for (size_t i = 0; i < intArray.size(); i++)
        intArray2[i] = i * 5;
    print<int>(intArray);
    print<int>(intArray2);
    return 0;
}