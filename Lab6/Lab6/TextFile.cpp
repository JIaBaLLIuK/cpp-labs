#include "TextFile.h"

TextFile::TextFile(string fileName) : AbstractFile(fileName)
{ }

void TextFile::ReadFromFile()
{
    in.open(fileName);
    string buffer;
    while (in >> buffer)
    {
        cout << buffer << endl;
    }

    in.close();
}

ostream& operator<<(ostream& stream, TextFile& file)
{
    file.in.open(file.fileName);
    string buffer;
    while (file.in >> buffer)
    {
        stream << buffer << endl;
    }

    file.in.close();
    return stream;
}
