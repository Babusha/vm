# include "Heap.hpp"
using namespace dynamic;

Heap::Heap(){};
Heap::~Heap() {};

ptr Heap::create(var value)
{
    Object object;
    object.value = value;
    object.refers++;
    heap.push_back(&object);
    return heap.size()-1;
}

void Heap::free(ptr address)
{
    Object* object = heap[address];
    heap.erase(heap.begin()+address);
}

void Heap::Dump()
{

}

size_t Heap::size()
{
    return heap.size();
}

Object* Heap::operator[](ptr address)
{
    if(address >= size())
        throw "Heap doesn't have this address";
    return heap[address];
}