#ifndef BTC_HPP
#define BTC_HPP
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <climits>

#define INPUT 1
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