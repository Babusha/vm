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
		reg[IP] = bytecode->GetPointer();
		byte var1, var2, var3, var4;
		var value;
		unsigned short int type;
		var exit_code;

		switch(VALUE)
		{
			case OBJECT:
				NEXT_OPC;
				var1 = VALUE;
				NEXT_OPC;
				switch(var1)
				{
					case NEW:
					{
						NEXT_OPC;
						type = BYTES(2);
						NEXT_OPCS(2);
						switch(type)
						{
							case 0x0103:
								value = (signed int) BYTES(4);
								stack.Push(heap.create(value));
								NEXT_OPCS(4+1)
								break;
						}
					};
				}
				break;
			case VM:
				NEXT_OPC;
				switch(VALUE)
				{
					case NOP:
						NEXT_OPC;
						break;
					case DUMP:
						Dump();
						NEXT_OPC;
						break;
					case EXIT:
						if(stack.isEmpty())
						{
							return (signed int) reg[EX];
						}
						else
						{
							exit_code = (signed int) stack.Pop();
							return exit_code;
						}
				}
				break;
		}
	}
}

void Machine::Dump()
{
	bytecode->Dump(reg[IP]);
	stack.Dump();
	reg.Dump();

}