#include <stdexcept>
#include <iostream>
#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        PmergeMe mergeMe;
        try
        {
            mergeMe.parseInput_v(argv[1]);
            if (mergeMe.getInput_v().empty())
            {
                std::cerr << "Error: No valid input provided." << std::endl;
                return 1;
            }
            mergeMe.print(mergeMe.getInput_v());
            mergeMe.sorted_v = mergeMe.sortInputVector(mergeMe.getInput_v());
            mergeMe.sorted_d = mergeMe.sortInputDeque(mergeMe.getInput_d());

            mergeMe.print(mergeMe.getSorted_v());
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        return 1;
    }
    else {
        std::cerr << "Error: Invalid number of arguments, Must be 2 (porgram name and list of positive integers)" << std::endl;
        return 1;
    }
    return 0;
}
