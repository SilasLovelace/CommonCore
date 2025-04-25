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
            mergeMe.parseInput(argv[1]);
            if (mergeMe.getInput().empty())
            {
                std::cerr << "Error: No valid input provided." << std::endl;
                return 1;
            }
            mergeMe.sortInput(mergeMe.getInput());
            // mergeMe.printInput();
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
