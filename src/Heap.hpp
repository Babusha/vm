# ifndef HEAP_HPP
# define HEAP_HPP
# include <vector>
# include "Object.hpp"
# include "Byte.hpp"
# include "dynamic/Dynamic.hpp"

typedef unsigned int ptr;

class Heap
{
    std::vector<Object*> heap;
public:
    Heap();
    ~Heap();
    ptr create(dynamic::var value);
    void free(ptr address);
    void Dump();
    size_t size();
    Object* operator[](ptr address);
};
# endif