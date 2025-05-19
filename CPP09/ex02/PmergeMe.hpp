#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <ctime>

#include <deque>

typedef std::vector<std::vector<int> > vector_int;
typedef std::vector<std::pair<std::vector<int>, std::vector<int> > > vector_int_pair;
typedef std::vector<std::vector<int> >::iterator i_v_iterator;
typedef std::vector<std::pair<std::vector<int>, std::vector<int> > >::iterator i_pair_v_iterator;

typedef std::deque<int>::iterator i_d_iterator;
typedef std::deque<std::pair<int, int> >::iterator i_pair_d_iterator;

class PmergeMe
{
    private:
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
    public:
        std::vector<std::vector<int> > input_v;
        std::deque<int> input_d;
        std::vector<std::vector<int> > sorted_v;
        std::deque<int> sorted_d;
        int comparisons;
        PmergeMe();
        ~PmergeMe();
        std::vector<std::vector<int> >& getInput_v() ;
        std::deque<int>& getInput_d() ;
        std::vector<std::vector<int> >& getSorted_v() ;
        std::deque<int>& getSorted_d() ;
        size_t jacobsthal(int n);
        void parseInput_v(int argc, char* argv[]);
        void parseInput_d(const std::string &inputStr);
        std::vector<std::vector<int> > sortInputVector(std::vector<std::vector<int> > &input);
        std::deque<int> sortInputDeque(std::deque<int> &input);
        void print_v(std::vector<std::vector<int> > v) const;
        void print_d(std::deque<int> d) const;
        void sort_pairs_v(std::vector<std::pair<std::vector<int>, std::vector<int> > > &pairs);

};
    

#endif