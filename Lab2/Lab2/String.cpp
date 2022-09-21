#include <iostream>
#include "String.h"

using namespace std;

String::String(char* _myString)
{
	length = strlen(_myString);
	myString = new char[length + 1];
	memcpy(myString, _myString, length);
	myString[length] = '\0';
}

String::String(const String& another)
{
	length = another.length;
	myString = new char[length + 1];
	memcpy(myString, another.myString, length + 1);
}

String::~String()
{
	delete[]myString;
}

void String::PrintString() const
{
	cout << myString << endl;
}

String& String::operator = (const String& another)
{
	length = another.length;
	if (myString)
	{
		delete[]myString;
	}
	myString = new char[length];
	for (int i = 0; i < length; i++)
	{
		myString[i] = another.myString[i];
	}
	return *this;
}

String String::operator + (const String& another) const
{
	String newString;
	newString.length = length + another.length;
	newString.myString = new char[newString.length + 1];
	for (int i = 0; i < length; i++)
	{
		newString.myString[i] = myString[i];
	}
	for (int i = length; i < newString.length; i++)
	{
		newString.myString[i] = another.myString[i - length];
	}
	newString.myString[newString.length] = '\0';
	return newString;
}

bool String::operator == (const String& another) const
{
	return !(strcmp(myString, another.myString));
}

bool String::operator != (const String& another) const
{
	return strcmp(myString, another.myString);
}

char String::operator[] (int index) const
{
	return myString[index];
}

String& String::operator+=(const String& another)
{
	int tempLength = length;
	length += another.length;
	char* buffer = new char[tempLength + 1];

	for (int i = 0; i < tempLength; i++)
	{
		buffer[i] = myString[i];
	}
	buffer[tempLength] = '\0';

	delete[]myString;
		
	myString = new char[length + 1];
	
	for (int i = 0; i < tempLength; i++)
	{
		myString[i] = buffer[i];
	}
	for (int i = tempLength; i < length; i++)
	{
		myString[i] = another.myString[i - tempLength];
	}
	myString[length] = '\0';
	return *this;
}

char* String::operator()(int start, int end) const
{
	int newSize = end - start + 1;
	char* newString = new char[newSize + 1];
	for (int i = start; i <= end; i++)
	{
		newString[i - start] = myString[i];
	}
	newString[newSize] = '\0';
	return newString;
}
