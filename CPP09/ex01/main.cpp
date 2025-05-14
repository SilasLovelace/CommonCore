#include "RPN.hpp"

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        RPN rpn;
        try{
            rpn.execute(argv[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Wrong number of arguments: " << std::endl;
        return 1;
    }
    return 0;
}
