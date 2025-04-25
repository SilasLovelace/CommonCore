#include "PmergeMe.hpp"
#include <iostream>
#include <vector>


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) : input(src.input), sorted(src.sorted) {}
PmergeMe::~PmergeMe() {}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->input = rhs.input;
        this->sorted = rhs.sorted;
    }
    return *this;
}

std::list<int>& PmergeMe::getInput()
{
    return this->input;
}
std::vector<int>& PmergeMe::getSorted() 
{
    return this->sorted;
}

void PmergeMe::parseInput(const std::string &inputStr)
{
    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token)
    {
        try
        {
             // Check if token is made of only digits (no sign, no dot)
            if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Invalid input: " + token);

            std::istringstream converter(token);
            int num;
            converter >> num;

            // Extra validation just in case (though the regex above should cover it)
            if (converter.fail() || num < 0)
                throw std::invalid_argument("Invalid input: " + token);

            input.push_back(num);
        }
        catch (const std::invalid_argument &e)
        {
            throw std::invalid_argument("Invalid input: " + token);
        }
    }
}

// void PmergeMe::printInput() const
// {
//     std::cout << "Input: ";
//     i_list_iterator begin =  this->input.begin();
//     i_list_iterator end = this->input.end();
//     for (i_list_iterator it = begin; it != end; ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// void PmergeMe::printSorted() const
// {
//     std::cout << "Sorted: ";
//     i_list_iterator begin =  this->input.begin();
//     i_list_iterator end = this->input.end();
//     for (i_list_iterator it = begin; it != end; ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

void sort_pairs(std::list<std::pair<int, int> > &pairs)
{
    std::cout << "Sorting pairs..." << std::endl;
    i_pair_iterator begin =  pairs.begin();
    i_pair_iterator end =  pairs.end();
    for (i_pair_iterator it = begin; it != end; ++it)
    {
         if (it->first > it->second)
         {
             int temp = it->first;
             it->first = it->second;
             it->second = temp;
         }
    }
}

std::vector<int> PmergeMe::sortInput(&std::vector<int>)
{
    std::list<std::pair<int, int> > pairs;
    i_list_iterator begin = this->input.begin();
    i_list_iterator end = this->input.end();
    int singleton = -1;

    i_list_iterator it = begin;
    while (it != end)
    {
        i_list_iterator next = it;
        ++next;
        if (next != end)
        {
            pairs.push_back(std::make_pair(*it, *next));
            it = ++next; // advance past the pair
        }
        else
        {
            singleton = *it;
            break;
        }
    }

    // Sort pairs
    sort_pairs(pairs);
    std::vector<int> top;

    // For debug output
    std::cout << "Pairs: ";
    for (i_pair_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        std::cout << "(" << pit->first << "," << pit->second << ") ";
    }
    std::cout << std::endl;

    if (singleton != -1)
        std::cout << "Singleton: " << singleton << std::endl;
}

// void PmergeMe::printSorted() const
// {
//     std::cout << "Sorted: ";
//     i_list_iterator begin =  this->sorted.begin();
//     i_list_iterator end = this->sorted.end();
//     for (i_list_iterator it = begin; it != end; ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }