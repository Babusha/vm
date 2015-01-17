# ifndef FILE_HPP
# define FILE_HPP

# include <iostream>

class File
{
	const char *path;
	char* data;
	size_t size;
	FILE *file;
public:
	File(const char* Path);
	~File();
	size_t Size();
	char* ByteArray();
};
# endif