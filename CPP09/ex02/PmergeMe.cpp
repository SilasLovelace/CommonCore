#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe() : comparisons(0) {}
PmergeMe::~PmergeMe() {}

v_v_int& PmergeMe::getInput_v()
{
    return this->input_v;
}

v_v_int& PmergeMe::getSorted_v() 
{
    return this->sorted_v;
}

d_d_int& PmergeMe::getInput_d()
{
    return this->input_d;
}
d_d_int& PmergeMe::getSorted_d() 
{
    return this->sorted_d;
}
void PmergeMe::parseInput_d(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i) 
    {
        std::string token(argv[i]);
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
        std::deque<int> d;
        d.push_back(num);
        input_d.push_back(d);
    }
}

void PmergeMe::parseInput_v(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i) 
    {
        std::string token(argv[i]);
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

void PmergeMe::sort_pairs_v(v_pair_v_int&pairs)
{
    pair_v_i_iterator begin =  pairs.begin();
    pair_v_i_iterator end =  pairs.end();
    int i = 0;
    for (pair_v_i_iterator it = begin; it != end; ++it)
    {
         if (it->first[0] > it->second[0])
         {
             std::vector<int> temp = it->first;
             it->first = it->second;
             it->second = temp;
            }
        comparisons++;
        it->first.push_back(i);
        it->second.push_back(i);
        i++;
    }
}
void PmergeMe::sort_pairs_d(d_pair_d_int &pairs)
{
    pair_d_i_iterator begin =  pairs.begin();
    pair_d_i_iterator end =  pairs.end();
    int i = 0;
    for (pair_d_i_iterator it = begin; it != end; ++it)
    {
         if (it->first[0] > it->second[0])
         {
             std::deque<int> temp = it->first;
             it->first = it->second;
             it->second = temp;
        }
        it->first.push_back(i);
        it->second.push_back(i);
        i++;
    }
}

std::deque<int> find_partner_d (d_pair_d_int &pairs, d_d_int &right_hand, int j_t_num, d_i_iterator &upper)
{
    d_i_iterator it = right_hand.begin();
    while (it != right_hand.end() && *(it->begin()) != j_t_num)
        ++it;
    upper = it;
    if (it == right_hand.end())
        throw std::invalid_argument("Error: No sorted partner found for index");
    pair_d_i_iterator pit = pairs.begin();
    while (pit != pairs.end() && upper->back() != pit->first.back())
        ++pit;
    if (pit == pairs.end())
        throw std::invalid_argument("Error: No unsorted partner found for index");
    pit->first.insert(pit->first.begin(), -1);
    return pit->first;
}

std::vector<int> find_partner_v (v_pair_v_int &pairs, v_v_int &right_hand, int j_t_num, v_i_iterator &upper)
{
    v_i_iterator it = right_hand.begin();
    while (it != right_hand.end() && *(it->begin()) != j_t_num)
        ++it;
    upper = it;
    if (it == right_hand.end())
        throw std::invalid_argument("Error: No sorted partner found for index");
    pair_v_i_iterator pit = pairs.begin();
    while (pit != pairs.end() && upper->back() != pit->first.back())
        ++pit;
    if (pit == pairs.end())
        throw std::invalid_argument("Error: No unsorted partner found for index");
    pit->first.insert(pit->first.begin(), -1);
    return pit->first;
}

void add_indices_d (d_d_int &sorted)
{
    d_i_iterator it = sorted.begin();
    int i = 0;
    while (it != sorted.end())
    {
        it->insert(it->begin(), i);
        it++;
        i++;
    }
}

void add_indices_v (v_v_int &sorted)
{
    v_i_iterator it = sorted.begin();
    int i = 0;
    while (it != sorted.end())
    {
        it->insert(it->begin(), i);
        it++;
        i++;
    }
}

std::deque<int> generateJacobsthalPattern_d(int N) {
    N++;
    //0, 1, 3, 5, 11, 21, 43
    // 0, 1, 3, 2, 5 , 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= N)
            break;
        jacobsthal.push_back(next);
    }
    
    std::deque<int> result;
    if (N > 2) {
        jacobsthal.erase(jacobsthal.begin(), jacobsthal.begin() + 2);
    }

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i];
        int end; 
        if (i == 0)
            end = 0;
        else
            end = jacobsthal[i - 1];

        for (int num = start; num > end; --num)
            result.push_back(num);
    }

    if (jacobsthal.back() < N) {
        for (int num = N - 1; num > jacobsthal.back(); --num) {
            result.push_back(num);
         }
    }

    for (size_t i = 0; i < result.size(); ++i) 
        result[i] = result[i] - 1;
    return result;
}

std::vector<int> generateJacobsthalPattern(int N) {
    N++;
    //0, 1, 3, 5, 11, 21, 43
    // 0, 1, 3, 2, 5 , 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= N)
            break;
        jacobsthal.push_back(next);
    }
    
    std::vector<int> result;
    if (N > 2) {
        jacobsthal.erase(jacobsthal.begin(), jacobsthal.begin() + 2);
    }

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i];
        int end ;
        if (i == 0)
            end = 0;
        else
            end = jacobsthal[i - 1];

        for (int num = start; num > end; --num)
            result.push_back(num);
    }

    if (jacobsthal.back() < N) {
        for (int num = N - 1; num > jacobsthal.back(); --num) {
            result.push_back(num);
         }
    }

    for (size_t i = 0; i < result.size(); ++i) 
        result[i] = result[i] - 1;
    return result;
}

d_d_int PmergeMe::sortInputDeque(d_d_int &input)
{
    if (input.size() < 2)
        return input;

    std::deque<int> singleton;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        singleton.insert(singleton.begin(), -1);
        singleton.push_back(-1);
    }

    d_pair_d_int pairs;
    d_i_iterator end = input.end();
    d_i_iterator it = input.begin();
    while (it != end && (it + 1) != end)
    {
        std::deque<int> left = *it;
        std::deque<int> right = *(it + 1);
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    //sorts left right and assigns pair-indeces for current level

    sort_pairs_d(pairs);

    d_d_int right_hand;
    for (pair_d_i_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputDeque(right_hand);
    add_indices_d(right_hand);
    //at this point all right hand have the indices of the respective pair per level as the top
    //and their own indices in the original sorted order as bottom
    int right_hand_size = right_hand.size();
    std::deque<int> jacobsthal = generateJacobsthalPattern_d(singleton.size() >  0 ? right_hand.size() + 1 : right_hand.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        d_i_iterator upper;
        std::deque<int> to_insert;
        if ((jacobsthal[i]) == right_hand_size)
        {
            to_insert = singleton;
            upper = right_hand.end();
        }
        else
            to_insert = find_partner_d(pairs, right_hand, jacobsthal[i], upper);
        d_i_iterator lower = right_hand.begin();
        d_i_iterator median = lower + (upper - lower + 1)/2;
        while (lower < upper)
        {
            median = lower + (upper - lower) / 2;
            if (to_insert[1] > (*median)[1])
                lower = median + 1;
            else
                upper = median;
        }
        right_hand.insert(lower, to_insert);
    }
    for (d_i_iterator it = right_hand.begin(); it != right_hand.end(); ++it)
    {
        it->pop_back();
        it->erase(it->begin());
    }
    return right_hand;
}

v_v_int PmergeMe::sortInputVector(std::vector<std::vector<int> > &input)
{
    if (input.size() < 2)
        return input;

    std::vector<int> singleton;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        singleton.insert(singleton.begin(), -1);
        singleton.push_back(-1);
    }

    v_pair_v_int pairs;
    v_i_iterator end = input.end();
    v_i_iterator it = input.begin();
    while (it != end && (it + 1) != end)
    {
        std::vector<int> left = *it;
        std::vector<int> right = *(it + 1);
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    //sorts left right and assigns pair-indeces for current level
    sort_pairs_v(pairs);

    v_v_int right_hand;
    for (pair_v_i_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputVector(right_hand);
    add_indices_v(right_hand);
    //at this point all right hand have the indices of the respective pair per level as the top
    //and their own indices in the original sorted order as bottom
    int right_hand_size = right_hand.size();
    std::vector<int> jacobsthal = generateJacobsthalPattern(singleton.size() >  0 ? right_hand.size() + 1 : right_hand.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        v_i_iterator upper;
        std::vector<int> to_insert;
        if ((jacobsthal[i]) == right_hand_size)
        {
            to_insert = singleton;
            upper = right_hand.end();
        }
        else
            to_insert = find_partner_v(pairs, right_hand, jacobsthal[i], upper);
        v_i_iterator lower = right_hand.begin();
        v_i_iterator median = lower + (upper - lower + 1)/2;
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
    for (v_i_iterator it = right_hand.begin(); it != right_hand.end(); ++it)
    {
        it->pop_back();
        it->erase(it->begin());
    }
    return right_hand;
}

void PmergeMe::print_v(v_v_int v) const
{
    v_i_iterator begin =  v.begin();
    v_i_iterator end = v.end();
    for (v_i_iterator it = begin; it != end; ++it)
    {
        for (size_t i = 0; i < it->size(); ++i)
        {
            std::cout << (*it)[i];
        }
        if (it + 1 != end)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_d(d_d_int d) const
{
    d_i_iterator begin =  d.begin();
    d_i_iterator end = d.end();
    for (d_i_iterator it = begin; it != end; ++it)
    {
        for (size_t i = 0; i < it->size(); ++i)
        {
            std::cout << (*it)[i];
        }
        if (it + 1 != end)
            std::cout << ", ";
    }
    std::cout << std::endl;
}
