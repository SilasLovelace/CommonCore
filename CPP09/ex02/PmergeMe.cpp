#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe() : comparisons(0) {}
PmergeMe::~PmergeMe() {}

std::vector<std::vector<int> >& PmergeMe::getInput_v()
{
    return this->input_v;
}

std::vector<std::vector<int> >& PmergeMe::getSorted_v() 
{
    return this->sorted_v;
}

// void PmergeMe::parseInput_v(const std::string &inputStr)
// {
//     std::istringstream iss(inputStr);
//     std::string token;
//     while (iss >> token)
//     {
//         if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
//             throw std::invalid_argument("NaN or Negative: " + token);

//         int num = 0;
//         for (std::string::size_type i = 0; i < token.length(); ++i)
//         {
//             num = num * 10 + (token[i] - '0');
//             if (num < 0)
//             {
//                 throw std::invalid_argument("Overflow of: " + token);
//                 break;
//             }
//         }
//         std::vector<int> vec;
//         vec.push_back(num);
//         input_v.push_back(vec);
//     }
// }

void PmergeMe::parseInput_v(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)  // start from 1 to skip the program name
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


void PmergeMe::sort_pairs_v(std::vector<std::pair<std::vector<int>, std::vector<int> > > &pairs)
{
    i_pair_v_iterator begin =  pairs.begin();
    i_pair_v_iterator end =  pairs.end();
    int i = 0;
    // std::cout << "sorting pairs" << std::endl;
    for (i_pair_v_iterator it = begin; it != end; ++it)
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
        // std::cout << "pair"<< i << ": ";
        // for (size_t j = 0; j < it->first.size(); ++j)
        //     std::cout << it->first[j] << " ";
        // std::cout << "; ";
        // for (size_t j = 0; j < it->second.size(); ++j)
        //     std::cout << it->second[j]  << " ";
        // std::cout << std::endl;
        i++;
    }
}

std::vector<int> find_partner_v (vector_int_pair &pairs, vector_int &right_hand, int j_t_num, i_v_iterator &upper)
{
    // std::cout << "jacobsthal index: "<< j_t_num << std::endl;
    i_v_iterator it = right_hand.begin();
    while (it != right_hand.end() && *(it->begin()) != j_t_num)
        ++it;
    // std::cout << "upper: " << *(it->begin()+1) << " " << it->back() << std::endl;
    upper = it;
    if (it == right_hand.end())
        throw std::invalid_argument("Error: 1No partner found");
    i_pair_v_iterator pit = pairs.begin();
    while (pit != pairs.end() && upper->back() != pit->first.back())
        ++pit;
    if (pit == pairs.end())
        throw std::invalid_argument("Error: 2No partner found");
    // std::cout << "partner: " << *(pit->first.begin())<< " " << pit->first.back() << std::endl;
    pit->first.insert(pit->first.begin(), -1);
    return pit->first;
}

void add_indices_v (std::vector<std::vector<int> > &sorted)
{
    i_v_iterator it = sorted.begin();
    int i = 0;
    // std::cout << "adding_indices_v" << std::endl;
    while (it != sorted.end())
    {
        it->insert(it->begin(), i);
        // for (size_t j = 0; j < it->size(); ++j)
        // {
        //     std::cout << (*it)[j] << " ";
        // }
        // std::cout << ",";
        it++;
        i++;
    }
    // std::cout << std::endl;
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

    // std::cout << "Jacobsthal numbers: ";
    // for (size_t i = 0; i < jacobsthal.size(); ++i) {
    //     std::cout << jacobsthal[i] << " ";
    // }
    // std::cout << std::endl;

      for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i];
        int end = jacobsthal[i - 1];

        for (int num = start; num > end; --num) {
            result.push_back(num);
            // std::cout << num << " ";
        }

    }
    if (jacobsthal.back() < N) {
            for (int num = N - 1; num > jacobsthal.back(); --num) {
        result.push_back(num);
        // std::cout << num << " ";
    }
    }

    for (size_t i = 0; i < result.size(); ++i) 
        result[i] = result[i] - 1;
    // std::cout << std::endl;
    return result;
}


std::vector<std::vector<int> > PmergeMe::sortInputVector(std::vector<std::vector<int> > &input)
{
    // print_v(input);
    if (input.size() < 2)
        return input;

    std::vector<int> singleton;
    if (input.size() % 2 != 0)
    {
        singleton = input.back();
        singleton.insert(singleton.begin(), -1);
        singleton.push_back(-1);
    }

    std::vector<std::pair<std::vector<int>,std::vector<int> > > pairs;
    i_v_iterator end = input.end();
    i_v_iterator it = input.begin();
    while (it != end && (it + 1) != end)
    {
        std::vector<int> left = *it;
        std::vector<int> right = *(it + 1);
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    //sorts left right and assigns pair-indeces for current level
    sort_pairs_v(pairs);

    std::vector<std::vector<int> > right_hand;
    for (i_pair_v_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        right_hand.push_back(pit->second);
    right_hand = sortInputVector(right_hand);
    add_indices_v(right_hand);
    //at this point all right hand have the indices of the respective pair per level as the top
    //and their own indices in the original sorted order as bottom
    std::vector<int> jacobsthal = generateJacobsthalPattern(right_hand.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        i_v_iterator upper;
        std::vector<int> to_insert = find_partner_v(pairs, right_hand, jacobsthal[i], upper);
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
        // std::cout << "Inserting" << std::endl;
        right_hand.insert(lower, to_insert);
        // print_v(right_hand);
    }
    if (singleton.size() > 0)
    {
        // std::cout << "singleton: ";
        // for (size_t i = 0; i < singleton.size(); ++i)
        //     std::cout << singleton[i] << " ";
        // std::cout << std::endl;
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

void PmergeMe::print_v(std::vector<std::vector<int> > v) const
{
    i_v_iterator begin =  v.begin();
    i_v_iterator end = v.end();
    for (i_v_iterator it = begin; it != end; ++it)
    {
        for (size_t i = 0; i < it->size(); ++i)
        {
            std::cout << (*it)[i] << " ";
        }
        std::cout << ",";
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