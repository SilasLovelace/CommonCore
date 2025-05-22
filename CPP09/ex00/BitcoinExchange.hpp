#ifndef BTC_HPP
#define BTC_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
    private:
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        std::map<std::string, float> rates;

         void parsefile(std::string filename);
         void parseinput(std::string filename);
};

#endif