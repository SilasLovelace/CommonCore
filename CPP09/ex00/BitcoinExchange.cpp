#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};

bool isValidNumber(const std::string &s, float &value) {
    if (s.find_first_not_of("0123456789.") != std::string::npos)
        return false;
    value = std::strtof(s.c_str(), NULL);
    if (value < 0 || value > 100)
        return false;
    return !s.empty();
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (year == 2009 && month == 1 && day == 1)
        return false;
    return day <= daysInMonth[month - 1] && year >= 2009;
}

bool checkformat(const std::string &line, float &btc) {
    std::string date, value;
    if (line.length() < 14 ||line[11] != '|' || line[10] != ' ' || line[12] != ' ')
        throw std::runtime_error("Error: bad input");

    date = line.substr(0, 10);
    value = line.substr(13, line.length() - 13);

    if (date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: bad date format, must be YYYY-MM-DD");
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (!isValidDate(year, month, day))
        throw std::runtime_error("Error: Invalid Date");

    if (!isValidNumber(value, btc))
        throw std::runtime_error("Error: not a valid number");

    return true;
}

void BitcoinExchange::parsefile(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        rates[line.substr(0, 10)] = std::strtof(line.substr(11, line.length() - 11).c_str(), NULL);
    }
    file.close();
}

void BitcoinExchange::parseinput(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Error: first line must be date | value");
    float value;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        try {
            checkformat(line, value);
            std::map<std::string, float>::iterator it = rates.lower_bound(line.substr(0, 10));
            if (it->first != line.substr(0, 10))
                it--;
            std::cout << line << " -> " << it->second * value << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << line << " -> ";
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}