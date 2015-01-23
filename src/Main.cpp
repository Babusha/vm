# include "Bytecode.hpp"
# include "File.hpp"
# include "Machine.hpp"
# include "Colors.hpp"
# include <signal.h>


int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		cout << "Use: " << argv[0] << " <path> " << endl;
		exit(1);
	}
	signal(SIGINT,[](int sig){
		throw(sig);
	});

	File file(argv[1]);
	auto *code = file.ByteArray();
	Bytecode *bytecode = new Bytecode((byte*) code,file.Size());
	Machine machine(bytecode);

	int exit_code;
	try
	{
		exit_code = machine.ExecuteCode();
	} catch(int sig)
	{
		cout << "\b\b"; // Deleting "^C"
		machine.Dump();
		exit(sig);
	} catch(const char* message)
	{
		machine.Dump();
		cout << endl << BOLDRED << message << RESET << endl;
	}
	return exit_code;
}