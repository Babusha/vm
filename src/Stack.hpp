# ifndef STACK_HPP
# define STACK_HPP

# include <vector>
using namespace std;
class Stack
{
	vector<unsigned int> stack;
public:
	Stack();
	~Stack();
	void Push(unsigned Item);
	unsigned int Pop();
	void Dump();
	bool isEmpty();
	unsigned int Top();
};
# endif