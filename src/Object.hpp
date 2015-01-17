# ifndef OBJECT_HPP
# define OBJECT_HPP

# include "dynamic/Dynamic.hpp"

struct Object
{
    dynamic::var value;
    unsigned int refers = 0;
};
# endif

