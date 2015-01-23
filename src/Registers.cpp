# include "Registers.hpp"
# include "Colors.hpp"
# include "Opcodes.hpp"
# include <iostream>

using namespace std;

Registers::Registers() { };

Registers::~Registers() { };

ptr Registers::operator [](byte i) const
{
	return registers[i];
}

ptr & Registers::operator [](byte i)
{
	return registers[i];
}
void Registers::Dump()
{
	cout << BOLDWHITE << "Registers: " << RESET << endl;
	cout << BOLDRED << "IP: 0x" << hex << uppercase << registers[0] << RESET << endl;
	/*cout << "AX: 0x" << hex << uppercase << registers[AX] << endl;
	cout << "BX: 0x" << hex << uppercase << registers[BX] << endl;
	cout << "CX: 0x" << hex << uppercase << registers[CX] << endl;
	cout << "DX: 0x" << hex << uppercase << registers[DX] << endl;
	cout << "EX: 0x" << hex << uppercase << registers[EX] << endl;
	cout << "FX: 0x" << hex << uppercase << registers[FX] << endl << endl;*/
}