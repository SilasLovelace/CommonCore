#ifndef BTC_HPP
#define BTC_HPP
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <climits>

class BitcoinExchange
{
    private:
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        std::map<std::string, int> rates;

        void parseinput(std::string input);
        void parsefile(std::string filename);
};

#endif