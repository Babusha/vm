# include "Machine.hpp"
# include "Opcodes.hpp"
# define DEBUG(str) cout << str << endl;
# define DEBUG_HEX(num) cout << "0x" << hex << (unsigned int)num << endl;

# define CURRENT_OPC bytecode->CurrentOpcode()
# define NEXT_OPC bytecode->Next()
# define NEXT_OPCS(n) bytecode->Next(n);
# define BYTES(n) bytecode->Bytes(n)
# define BYTE_ARRAY(from,offset) bytecode->ByteArray(from,offset)
# define JUMP(address) bytecode->Jump(address)
# define loop while(true)
using namespace std;
using namespace dynamic;

Machine::Machine(Bytecode *_bytecode)
{
	bytecode = _bytecode;
	garbageCollector = new GarbageCollector(&heap);
}

Machine::~Machine() {};

int Machine::ExecuteCode()
{
	unsigned short type = 0;
	loop
	{
		reg[0] = bytecode->GetPointer();
		switch(CURRENT_OPC)
		{
			case NOP:
				NEXT_OPC;
			break;
			
			case DUMP:
				NEXT_OPC;
				Dump();
			break;

			case EXIT:
				return 0;

			case INT:
				stack.Push(heap.create( (signed) BYTES(4)));
				NEXT_OPCS(4);
			break;

		}
	}
}

void Machine::Dump()
{
	bytecode->Dump(reg[0]);
	stack.Dump();
	reg.Dump();

}