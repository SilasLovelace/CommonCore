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

typedef std::vector<std::vector<int> > v_v_int;
typedef std::vector<std::pair<std::vector<int>, std::vector<int> > > v_pair_v_int;
typedef std::vector<std::vector<int> >::iterator v_i_iterator;
typedef std::vector<std::pair<std::vector<int>, std::vector<int> > >::iterator pair_v_i_iterator;

typedef std::deque<std::deque<int> > d_d_int;
typedef std::deque<std::pair<std::deque<int>, std::deque<int> > > d_pair_d_int;
typedef std::deque<std::deque<int> >::iterator d_i_iterator;
typedef std::deque<std::pair<std::deque<int>, std::deque<int> > >::iterator pair_d_i_iterator;

class PmergeMe
{
    private:
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
    public:
        v_v_int input_v;
        v_v_int sorted_v;
        d_d_int input_d;
        d_d_int sorted_d;
        int comparisons;
        PmergeMe();
        ~PmergeMe();
        v_v_int& getInput_v() ;
        v_v_int& getSorted_v() ;
        d_d_int& getInput_d() ;
        d_d_int& getSorted_d() ;
        size_t jacobsthal(int n);
        void parseInput_v(int argc, char* argv[]);
        void parseInput_d(int argc, char* argv[]);
        v_v_int sortInputVector(v_v_int &input);
        d_d_int sortInputDeque(d_d_int &input);
        void print_v(v_v_int v) const;
        void print_d(d_d_int d) const;
        void sort_pairs_v(v_pair_v_int &pairs);
        void sort_pairs_d(d_pair_d_int &pairs);
};
    

#endif