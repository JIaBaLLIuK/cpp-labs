#ifndef BINARY_FILE_H
#define BINARY_FILE_H

#include "AbstractFile.h"

class BinaryFile : public AbstractFile
{
public:
	BinaryFile(string);
	~BinaryFile() = default;

	template <class Type>
	void WriteToFile(Type);
	template <class Type>
	void ReadFromFile(Type&);
};

template<class Type>
void BinaryFile::WriteToFile(Type data)
{
	out.open(fileName, ios::binary | ios::app);
	out.write((char*)&data, sizeof(Type));
	out.close();
}

template<class Type>
void BinaryFile::ReadFromFile(Type& buffer)
{
	in.open(fileName, ios::binary);
	while (in.read((char*)&buffer, sizeof(buffer)))
	{
		cout << buffer << endl;
	}

	in.close();
}

#endif
