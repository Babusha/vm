# include "Stack.hpp"
# include "Hexdump.hpp"
# include "Colors.hpp"
# include "Byte.hpp"
# include <iostream>
using namespace std;

Stack::Stack() { }

Stack::~Stack() { }

void Stack::Push(unsigned int Item)
{
	stack.push_back(Item);
}

unsigned int Stack::Pop()
{
	int back = stack.back();
	stack.pop_back();
	return back;
}

void Stack::Dump()
{
	cout << BOLDWHITE << "Stack: " << RESET << endl;
	if(isEmpty())
	{
		cout << "< stack empty >" << endl << endl;
		return;
	}
	vector<byte> stack_data;
	for(unsigned int i = 0; i < stack.size(); i++)
		for(int j = sizeof(unsigned int)-1; j >= 0; j--)
			stack_data.push_back( (stack[i] >> 8*j) & 255);
    hexdump(stack_data.data(),stack_data.size());
    cout << endl << endl;
}

bool Stack::isEmpty()
{
	return stack.size() == 0;
}

unsigned int Stack::Top()
{
	return stack.back();
}

unsigned int Stack::operator [](unsigned int i) const
{
	return stack[stack.size()-i-1];
}