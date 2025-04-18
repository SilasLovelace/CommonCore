#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        int         _int;
        float       _float;
        double      _double;
        std::string _str;
    public:
        Data();
        Data(Data const &rhs);
        Data& operator=(Data const &rhs);
        virtual ~Data();
        int         getInt() const;
        float       getFloat() const;
        double      getDouble() const;
        std::string getStr() const;
};

#endif