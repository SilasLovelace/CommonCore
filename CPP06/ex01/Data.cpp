#include "Data.hpp"

Data::Data() : _int(0), _float(0.0f), _double(0.0), _str("test") {}
Data::~Data() {}
Data::Data(const Data &other) {
    *this = other;
}
Data &Data::operator=(const Data &other) {
    if (this != &other) {
        this->_int = other._int;
        this->_float = other._float;
        this->_double = other._double;
        this->_str = other._str;
    }
    return *this;
}
int Data::getInt() const {
    return this->_int;
}
float Data::getFloat() const {
    return this->_float;
}
double Data::getDouble() const {
    return this->_double;
}
std::string Data::getStr() const {
    return this->_str;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << "Data: { int: " << data.getInt() << ", float: " << data.getFloat()
       << ", double: " << data.getDouble() << ", str: " << data.getStr() << " }";
    return os;
}
