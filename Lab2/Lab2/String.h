#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
private:
	char* myString;
	int length;
public:
	String(char*);
	String(const String&);
	String() = default;
	~String();
	void PrintString() const;
	String& operator = (const String&);
	String operator + (const String&) const;
	bool operator == (const String&) const;
	bool operator != (const String&) const;
	char operator [] (int) const;
	String& operator += (const String&);
	char* operator () (int, int) const;
};

#endif


