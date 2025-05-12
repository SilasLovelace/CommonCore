#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

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

std::vector<int>& PmergeMe::getInput()
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
        if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Invalid input: " + token);

        int num = 0;
        bool valid = true;
        for (std::string::size_type i = 0; i < token.length(); ++i)
        {
            num = num * 10 + (token[i] - '0');
            if (num < 0) // Check for overflow
            {
                valid = false;
                break;
            }
        }

        if (!valid)
            throw std::invalid_argument("Invalid input: " + token);

        input.push_back(num);
    }
}

void sortPairs(std::vector<std::pair<int, int> > &pairs)
{
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

std::vector<int> PmergeMe::sortInput(std::vector<int> &input)
{
    // Handle base cases
    if (input.size() <= 1)
        return input;

    // Separate singleton if input size is odd
    int singleton = -1;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        input.pop_back();
    }

    // Create pairs
    std::vector<std::pair<int, int> > pairs;
    for (std::vector<int>::size_type i = 0; i < input.size(); i += 2)
    {
        pairs.push_back(std::make_pair(input[i], input[i+1]));
    }

    // Sort pairs based on larger element
    sortPairs(pairs);

    // Sort the larger elements recursively 
    std::vector<int> largerElements;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
        largerElements.push_back(it->second);
    
    largerElements = sortInput(largerElements);

    // Binary insertion of smaller elements
    std::vector<int> result = largerElements;
    for (std::vector<std::pair<int, int> >::const_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        // Manual lower_bound implementation for C++98
        std::vector<int>::iterator it = result.begin();
        while (it != result.end() && *it < pit->first)
            ++it;
        result.insert(it, pit->first);
    }

    // Handle singleton if it exists
    if (singleton != -1)
    {
        // Manual lower_bound implementation for C++98
        std::vector<int>::iterator it = result.begin();
        while (it != result.end() && *it < singleton)
            ++it;
        result.insert(it, singleton);
    }

    return result;
}

void PmergeMe::print(const std::vector<int> &v) const
{
    std::cout << "After sort: ";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
