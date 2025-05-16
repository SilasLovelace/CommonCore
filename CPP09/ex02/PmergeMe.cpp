#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe() : comparisons(0) {}
PmergeMe::~PmergeMe() {}

std::vector<std::vector<int>>& PmergeMe::getInput_v()
{
    return this->input_v;
}

std::vector<int>& PmergeMe::getSorted_v() 
{
    return this->sorted_v;
}

void PmergeMe::parseInput_v(const std::string &inputStr)
{
    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token)
    {
        if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("NaN or Negative: " + token);

        int num = 0;
        for (std::string::size_type i = 0; i < token.length(); ++i)
        {
            num = num * 10 + (token[i] - '0');
            if (num < 0)
            {
                throw std::invalid_argument("Overflow of: " + token);
                break;
            }
        }
        std::vector<int> vec;
        vec.push_back(num);
        input_v.push_back(vec);
    }
}


void PmergeMe::sort_pairs_v(std::vector<std::pair<std::vector<int>, std::vector<int>> > &pairs)
{
    i_pair_v_iterator begin =  pairs.begin();
    i_pair_v_iterator end =  pairs.end();
    int i = 0;
    for (i_pair_v_iterator it = begin; it != end; ++it)
    {
         if (it->first[0] > it->second[0])
         {
             comparisons++;
             int temp = it->first[0];
             it->first[0] = it->second[0];
             it->second[0] = temp;
         }
        it->first.push_back(i);
        it->second.push_back(i);
        i++;
    }
}

std::vector<int> find_partner_v (std::vector<std::pair<std::vector<int>,std::vector<int>> > &pairs, std::vector<std::vector<int>> &right_hand, int j_t_num, int &index)
{
    index = 0;
    i_v_iterator it = right_hand.begin();
    while (it != right_hand.end() && *(it->begin()) != j_t_num)
    {
        ++index;
        ++it;
    }
    if (it == right_hand.end())
        throw std::invalid_argument("Error: No partner found");
    i_pair_v_iterator pit = pairs.begin();
    while (pit != pairs.end() && it->back() != pit->first.back())
        ++pit;
    if (pit == pairs.end())
        throw std::invalid_argument("Error: No partner found");
    pit->second.insert(pit->second.begin(), -1);
    return pit->second;
}

void add_indices_v (std::vector<std::vector<int>> &sorted)
{
    i_v_iterator it = sorted.begin();
    int i = 0;
    while (it != sorted.end())
    {
        it->insert(it->begin(), i);
        ++it;
        i++;
    }
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


std::vector<std::vector<int>> PmergeMe::sortInputVector(std::vector<std::vector<int>> &input)
{
    if (input.size() < 2)
        return input;

    std::vector<int> singleton;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        singleton.insert(singleton.begin(), -1);
        input.pop_back();
    }
    
    std::vector<std::pair<std::vector<int>,std::vector<int>> > pairs;
    i_v_iterator end = input.end();
    i_v_iterator it = input.begin();
    while (it != end)
    {
        std::vector<int> left = *it;
        std::vector<int> right = *(it + 1);
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    //sorts left right and assigns pair-indeces for current level
    sort_pairs_v(pairs);

    std::vector<std::vector<int>> right_hand;
    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputVector(right_hand);
    add_indices_v(right_hand);
    //at this point all right hand have the indices of the respective pair per level as the top
    //and their own indices in the original sorted order as bottom
    int j_t_num = 0;
    for (i_v_iterator it = right_hand.begin(); it != right_hand.end(); ++it)
    {
        int index = 0;
        std::vector<int> to_insert = find_partner_v(pairs, right_hand, j_t_num, index);
        i_v_iterator upper = right_hand.begin() + index;
        i_v_iterator lower = right_hand.begin();
        i_v_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (to_insert[1] > (*median)[1])
                lower = median + 1;
            else
                upper = median;
            comparisons++;
        }
        right_hand.insert(lower, to_insert);
    }

    if (singleton.size() > 0)
    {
        i_v_iterator upper = right_hand.end();
        i_v_iterator lower = right_hand.begin();
        i_v_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (singleton[1] > (*median)[1])
                lower = median + 1;
            else
                upper = median;
            comparisons++;
        }
        right_hand.insert(lower, singleton);
    }
    //removes the current level pair indeces and right hand original indices
    for (i_v_iterator it = right_hand.begin(); it != right_hand.end(); ++it)
    {
        it->pop_back();
        it->erase(it->begin());
    }
    return right_hand;
}

void PmergeMe::print_v(std::vector<std::vector<int>> v) const
{
    i_v_iterator begin =  v.begin();
    i_v_iterator end = v.end();
    for (i_v_iterator it = begin; it != end; ++it)
    {
        std::cout << (*it)[0] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_d(std::deque<int> v) const
{
    i_d_iterator begin =  v.begin();
    i_d_iterator end = v.end();
    for (i_d_iterator it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}