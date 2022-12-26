#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class AbstractFile
{
public:
	AbstractFile(string);
	~AbstractFile() = default;

protected:
	string fileName;
	ofstream out;
	ifstream in;
};

#endif
