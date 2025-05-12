#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) : input(src.input_v), sorted_v(src.sorted_v), sorted_l(src.sorted_l) {}
PmergeMe::~PmergeMe() {}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->input_v = rhs.input_v;
        this->sorted_v = rhs.sorted_v;
        this->sorted_l = rhs.sorted_l;
    }
    return *this;
}

std::vector<int>& PmergeMe::getInput_v()
{
    return this->input_v;
}

std::deque<int>& PmergeMe::getInput_d()
{
    return this->input_d;
}
std::vector<int>& PmergeMe::getSorted_v() 
{
    return this->sorted_v;
}

std::deque<int>& PmergeMe::getSorted_d() 
{
    return this->sorted_d;
}

void PmergeMe::parseInput_v(const std::string &inputStr)
{
    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token)
    {
        if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Invalid input: " + token);

        int num = 0;
        for (std::string::size_type i = 0; i < token.length(); ++i)
        {
            num = num * 10 + (token[i] - '0');
            if (num < 0)
            {
                throw std::invalid_argument("Invalid input: " + token);
                break;
            }
        }
        input_v.push_back(num);
    }
}

void sort_pairs_v(std::vector<std::pair<int, int> > &pairs)
{
    i_pair_v_iterator begin =  pairs.begin();
    i_pair_v_iterator end =  pairs.end();
    for (i_pair_v_iterator it = begin; it != end; ++it)
    {
         if (it->first > it->second)
         {
             int temp = it->first;
             it->first = it->second;
             it->second = temp;
         }
    }
}

void sort_pairs_l(std::deque<std::pair<int, int> > &pairs)
{
    i_pair_l_iterator begin =  pairs.begin();
    i_pair_l_iterator end =  pairs.end();
    for (i_pair_l_iterator it = begin; it != end; ++it)
    {
         if (it->first > it->second)
         {
             int temp = it->first;
             it->first = it->second;
             it->second = temp;
         }
    }
}

std::vector<int> PmergeMe::sortInputVector(std::vector<int> &input)
{
    if (input.size() < 2)
        return input;

    int singleton = -1;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        input.pop_back();
    }
    
    std::vector<std::pair<int, int> > pairs;
    i_v_iterator end = input.end();
    i_v_iterator it = input.begin();
    while (it != end)
    {
            pairs.push_back(std::make_pair(*it, *(it + 1)));
            it += 2;
    }

    sort_pairs_v(pairs);

    std::vector<int> right_hand;
    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputVector(right_hand);

    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        int to_insert = pit->first;
        i_v_iterator upper = std::find(right_hand.begin(), right_hand.end(), pit->second);
        i_v_iterator lower = right_hand.begin();
        i_v_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (to_insert > *median)
                lower = median + 1;
            else
                upper = median;
        }
        right_hand.insert(lower, to_insert);
    }

    if (singleton != -1)
    {
        i_v_iterator upper = right_hand.end();
        i_v_iterator lower = right_hand.begin();
        i_v_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (singleton > *median)
                lower = median + 1;
            else
                upper = median;
        }
        right_hand.insert(lower, singleton);
    }

    return right_hand;
}
std::deque<int> sortInputdeque(std::deque<int> &input)
{
 if (input.size() < 2)
        return input;

    int singleton = -1;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        input.pop_back();
    }
    
    std::deque<std::pair<int, int> > pairs;
    i_l_iterator end = input.end();
    i_l_iterator it = input.begin();
    while (it != end)
    {
            pairs.push_back(std::make_pair(*it, *(it + 1)));
            it += 2;
    }

    sort_pairs_l(pairs);

    std::vector<int> right_hand;
    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputVector(right_hand);

    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        int to_insert = pit->first;
        i_l_iterator upper = std::find(right_hand.begin(), right_hand.end(), pit->second);
        i_l_iterator lower = right_hand.begin();
        i_l_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (to_insert > *median)
                lower = median + 1;
            else
                upper = median;
        }
        right_hand.insert(lower, to_insert);
    }

    if (singleton != -1)
    {
        i_l_iterator upper = right_hand.end();
        i_l_iterator lower = right_hand.begin();
        i_l_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (singleton > *median)
                lower = median + 1;
            else
                upper = median;
        }
        right_hand.insert(lower, singleton);
    }

    return right_hand;
}


void PmergeMe::print(std::vector<int> v) const
{
    i_v_iterator begin =  v.begin();
    i_v_iterator end = v.end();
    for (i_v_iterator it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}