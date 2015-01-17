# include "Bytecode.hpp"
# include "Hexdump.hpp"
# include "Colors.hpp"
# include <iostream>
# include <string.h>

using namespace std;

Bytecode::Bytecode(byte* array, size_t _Length)
{
	code = array;
	Length = _Length;
	Pointer = 0;
}

Bytecode::~Bytecode()
{
	delete[] code;
}

void Bytecode::Next(unsigned int to)
{
	Pointer += to;
}

void Bytecode::Prev(unsigned int to)
{
	Pointer += to;
}

void Bytecode::Jump(unsigned int Address)
{
	Pointer = Address;
}

byte Bytecode::Value(unsigned int offset)
{
	return code[Pointer+offset];
}

bool Bytecode::End()
{
	return Pointer > Length;
}

void Bytecode::Dump(int ptr)
{
	cout << BOLDWHITE << "Program: " << RESET << endl;
	if(ptr == -1)
		hexdump(code,Length);
	else 
		hexdump(code,Length,ptr);
	cout << endl;
}

unsigned int Bytecode::GetPointer()
{
	return Pointer;
}

unsigned int Bytecode::Bytes(size_t n)
{
	unsigned int res = 0;
	for(unsigned int offset = 0; offset < n; offset++)
	{
		res <<= 8;
		res += Value(offset);
	}
	return res;
}

unsigned int Bytecode::BytesFrom(unsigned int address,size_t n)
{
	unsigned int res = 0;
	for(size_t offset = 0; offset < n; offset++)
	{
		res <<= 8;
		res += code[address+offset];
	}
	return res;
}

byte* Bytecode::ByteArray(unsigned int begin, size_t length)
{
	byte* array = new byte[length];
	memcpy(array,code+begin,sizeof(byte)*length);
	return array;
}

void Bytecode::Rewrite(unsigned int pointer, byte data)
{
	code[pointer] = data;
}

byte Bytecode::operator [](unsigned int i) const
{
	return code[i];
}

byte& Bytecode::operator [](unsigned int i)
{
	return code[i];
}