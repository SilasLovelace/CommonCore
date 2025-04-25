#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

typedef std::vector<int>::iterator i_list_iterator;
typedef std::vector<std::pair<int, int> >::iterator i_pair_iterator;


class PmergeMe
{
    private:
        std::vector<int> input;
        std::vector<int> sorted;
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &rhs);
    public:
        PmergeMe();
        ~PmergeMe();
        std::list<int>& getInput() ;
        std::vector<int>& getSorted() ;
        void parseInput(const std::string &inputStr);
        std::vector<int> sortInput(std::vector<int>);
        // void printSorted() const;
        // void printInput() const;
};
    

#endif 