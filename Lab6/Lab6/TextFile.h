#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include "AbstractFile.h"

class TextFile : public AbstractFile
{
public:
	TextFile(string);
	~TextFile() = default;
	 
	template <class Type>
	void WriteToFile(Type);
	void ReadFromFile();
	template <class Type>
	friend TextFile& operator << (TextFile&, Type);
	friend ostream& operator << (ostream&, TextFile&);
};

template <class Type>
void TextFile::WriteToFile(Type data)
{
	out.open(fileName);
	out << data << endl;
	out.close();
}

template<class Type>
TextFile& operator<<(TextFile& file, Type data)
{
	file.out.open(file.fileName);
	file.out << data << endl;
	file.out.close();
	return file;
}

#endif
