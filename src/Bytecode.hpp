# ifndef BYTECODE_HPP
# define BYTECODE_HPP

# include "Byte.hpp"
# include <cstdlib>

class Bytecode
{
	byte* code;
	unsigned int Pointer,Length;
public:
	Bytecode(byte* array,size_t _Length);
	~Bytecode();
	void Next(unsigned int to = 1);
	void Prev(unsigned int to = 1);
	void Jump(unsigned int Address);
	byte CurrentOpcode(unsigned int offset = 0);
	bool End();
	void Dump(int ptr = -1);
	unsigned int GetPointer();
	unsigned int Bytes(size_t n);
	void Rewrite(unsigned int pointer, byte data);
	byte* ByteArray(unsigned int begin, size_t length);
	unsigned int BytesFrom(unsigned int address,size_t n);
	byte operator [](unsigned int i) const;
    byte & operator [](unsigned int i);
};
# endif