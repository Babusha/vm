# ifndef REGISTERS_HPP
# define REGISTERS_HPP
# include "Heap.hpp"
# include "Byte.hpp"
class Registers
{
	ptr registers[7] = { 0,0,0,0,0,0,0 };
public:
	Registers();
	~Registers();
	ptr operator [](byte i) const;
    ptr & operator [](byte i);
	void Dump();
};
# endif