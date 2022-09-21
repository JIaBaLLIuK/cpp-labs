#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	char* buffer = new char[50];
	cout << "Enter the first string:" << endl;
	gets_s(buffer, 50);
	String string1(buffer);
	String string2 = string1;
	cout << "string1 = ";
	string1.PrintString();
	cout << "string2 = ";
	string2.PrintString();
	cout << "Enter the third string:" << endl;
	gets_s(buffer, 50);
	String string3(buffer);
	String string4 = string1 + string3;
	cout << "string 4 = string1 + string2 = ";
	string4.PrintString();
	string4 += string2;
	cout << "string 4 += string 2 = ";
	string4.PrintString();
	if (string1 == string2)
	{
		cout << "string1 == string2" << endl;
	}
	else
	{
		cout << "string1 != string2" << endl;
	}
	if (string1 != string4)
	{
		cout << "string1 != string4" << endl;
	}
	else
	{
		cout << "string1 == string4" << endl;
	}
	cout << "string3[0] = " << string3[0] << endl;
	cout << "string1(1, 3) = " << string1(1, 3) << endl;
	return 0;
}