#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array{
    private:
        T* _array;
        size_t _size;
    public:
        Array(): _array(new T[0]) , _size(0){};
        Array(size_t size): _size(size){_array = new T[size];}
        Array(const Array& other): _size(other._size)
        {
            _array = new T[_size];
            for (size_t i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        Array& operator=(const Array& other){
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        };
        T& operator[](size_t index){
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        };
        ~Array(){
            delete[] _array;
        };
        size_t size() const{
            return _size;
        };
};

#endif