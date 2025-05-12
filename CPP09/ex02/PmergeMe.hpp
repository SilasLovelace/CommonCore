#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>

#include <deque>


typedef std::vector<int>::iterator i_v_iterator;
typedef std::vector<std::pair<int, int> >::iterator i_pair_v_iterator;

typedef std::deque<int>::iterator i_d_iterator;
typedef std::deque<std::pair<int, int> >::iterator i_pair_d_iterator;

class PmergeMe
{
    private:
        std::vector<int> input_v;
        std::deque<int> input_d;
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
    public:
        std::vector<int> sorted_v;
        std::deque<int> sorted_d;
        PmergeMe();
        ~PmergeMe();
        std::vector<int>& getInput_v() ;
        std::deque<int>& getInput_d() ;
        std::vector<int>& getSorted_v() ;
        std::deque<int>& getSorted_d() ;
        void parseInput_v(const std::string &inputStr);
        std::vector<int> sortInputVector(std::vector<int> &input);
        std::deque<int> sortInputDeque(std::vector<int> &input);
        void print(std::vector<int> v) const;
};
    

#endif 