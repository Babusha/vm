# ifndef OBJECT_HPP
# define OBJECT_HPP

# include "dynamic/Dynamic.hpp"

struct Object
{
    dynamic::var value;
    unsigned int refers = 0;
};
/*
template <class T>
class Object
{
    T _object;
public:
    unsigned int refers = 0;
    Object(T object)
    {
        _object = object;
    }
};*/
# endif

