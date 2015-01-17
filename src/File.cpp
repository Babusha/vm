# include "File.hpp"
# include <iostream>
File::File(const char* Path)
{
	path = Path;
	file = fopen(Path, "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	data = (char*) malloc(size);
	fread(data, size, 1, file);
	fclose(file);
}
File::~File()
{
	free(data);
}
size_t File::Size()
{
	return size;
}

char* File::ByteArray()
{
	return data;
}