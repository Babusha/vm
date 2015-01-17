# ifndef GARBAGE_COLLECTOR_HPP
# define GARBAGE_COLLECTOR_HPP
# include "Heap.hpp"

class GarbageCollector
{
    Heap* heap;
public:
    GarbageCollector(Heap *_heap);
    ~GarbageCollector();
    void CountRefers();
    void Collect();
};
# endif