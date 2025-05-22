#include <stdexcept>
#include <iostream>
#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc >= 2)
    {
        PmergeMe mergeMe;
        try {
            std::clock_t start = std::clock();
            mergeMe.parseInput_v(argc, argv);
            if (mergeMe.getInput_v().empty())
            {
                std::cerr << "Error: No valid input provided." << std::endl;
                return 1;
            }
            mergeMe.sorted_v = mergeMe.sortInputVector(mergeMe.getInput_v());
            std::clock_t end = std::clock();
            double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
            std::cout << "Input: ";
            mergeMe.print_v(mergeMe.getInput_v());
            std::cout << "Sorted: ";
            mergeMe.print_v(mergeMe.getSorted_v());
            std::cout << "Time taken to sort Vector of " << mergeMe.getInput_v().size() <<" elements: " << time << " microseconds" << std::endl;
            
            start = std::clock();
            mergeMe.parseInput_d(argc , argv);
            if (mergeMe.getInput_d().empty())
            {
                std::cerr << "Error: No valid input provided." << std::endl;
                return 1;
            }
            mergeMe.sorted_d = mergeMe.sortInputDeque(mergeMe.getInput_d());
            end = std::clock();
            time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
            // std::cout << "Input: ";
            // mergeMe.print_v(mergeMe.getInput_v());
            // std::cout << "Sorted: ";
            // mergeMe.print_v(mergeMe.getSorted_v());
            std::cout << "Time taken to sort Deque of " << mergeMe.getInput_d().size() <<" elements: " << time << " microseconds" << std::endl;
            
            // std::cout << "Number of comparisons: " << mergeMe.comparisons << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        return 1;
    }
    else {
        std::cerr << "Error: Invalid number of arguments, Must be at least 2 (program name and list of positive integers)" << std::endl;
        return 1;
    }
    return 0;
}
