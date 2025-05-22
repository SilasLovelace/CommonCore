#include "BitcoinExchange.hpp"

int main (int ac , char **av)
{
    if (ac == 2)
    {
        BitcoinExchange btc;
        try{
            btc.parsefile("data.csv");
            btc.parseinput(av[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Wrong number of arguments, provide one filname for input" << std::endl;
        return 1;
    }
    return 0;
}
