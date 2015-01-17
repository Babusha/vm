# include "Machine.hpp"
# include "Opcodes.hpp"
# define DEBUG(str) cout << str << endl;
# define DEBUG_HEX(num) cout << "0x" << hex << (unsigned int)num << endl;

# define VALUE bytecode->Value()
# define NEXT_OPC bytecode->Next()
# define NEXT_OPCS(n) bytecode->Next(n);
# define BYTES(n) bytecode->Bytes(n);
# define BYTE_ARRAY(from,offset) bytecode->ByteArray(from,offset)
# define JUMP(address) bytecode->Jump(address)
# define loop while(true)
using namespace std;

Machine::Machine(Bytecode *_bytecode)
{
	bytecode = _bytecode;
	garbageCollector = new GarbageCollector(&heap);
}

Machine::~Machine() {};

void Machine::ExecuteCode()
{
	unsigned short type = 0;
	loop
	{
		reg[IP] = bytecode->GetPointer();
		byte size;
		switch(VALUE)
		{

		}
	}
}

void Machine::Dump()
{
	bytecode->Dump(reg[IP]);
	stack.Dump();
	reg.Dump();

}