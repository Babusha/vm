# include "GarbageCollector.hpp"
# include "Object.hpp"


GarbageCollector::GarbageCollector(Heap * _heap)
{
    heap = _heap;
}

GarbageCollector::~GarbageCollector()
{
    //
}

void GarbageCollector::CountRefers()
{
    //
}

void GarbageCollector::Collect()
{
    Object *object;
    for(ptr address = 0; address < heap->size(); address++)
    {
        object = (*heap)[address];
        if(object->refers == 0)
            heap->free(address);
    }
}