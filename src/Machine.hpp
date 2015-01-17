# ifndef MACHINE_HPP
# define MACHINE_HPP

# include "Bytecode.hpp"
# include "Stack.hpp"
# include "Registers.hpp"
# include "Heap.hpp"
# include "GarbageCollector.hpp"

class Machine
{
	Stack stack;
	Registers reg;
	Bytecode *bytecode;
	Heap heap;
	GarbageCollector *garbageCollector;
public:
	Machine(Bytecode *_bytecode);
	~Machine();
	void Dump();
	void ExecuteCode();
};
# endif