#include <iostream>

#include "TextFile.h"
#include "BinaryFile.h"
#include "Stack.h"
#include "Car.h"

using namespace std;

template <class Type>
void InputNumber(Type& number)
{
	cout << "Enter the number:" << endl;
	cin >> number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		throw exception("wrong input");
	}
}

template<class Type>
void TryInputData(Type& number)
{
	bool isCorrect;
	do
	{
		try
		{
			InputNumber(number);
			isCorrect = true;

		}
		catch (const exception& exception)
		{
			cout << "Error: " << exception.what() << endl;
			isCorrect = false;
		}
	} while (!isCorrect);
}

int main()
{
	int power;
	cout << "INPUT INFORMATION ABOUT THE FIRST CAR" << endl;
	cout << "CAR POWER INPUT" << endl;
	TryInputData(power);
	int length;
	cout << "CAR LENGTH INPUT" << endl;
	TryInputData(length);
	int width;
	cout << "CAR WIDTH INPUT" << endl;
	TryInputData(width);
	int height;
	cout << "CAR HEIGHT INPUT" << endl;
	TryInputData(height);
	Car car1(power, length, width, height);
	cout << "INPUT INFORMATION ABOUT THE SECOND CAR" << endl;
	cout << "CAR POWER INPUT" << endl;
	TryInputData(power);
	cout << "CAR LENGTH INPUT" << endl;
	TryInputData(length);
	cout << "CAR WIDTH INPUT" << endl;
	TryInputData(width);
	cout << "CAR HEIGHT INPUT" << endl;
	TryInputData(height);
	Car car2(power, length, width, height);
	Stack<Car> stack;
	stack.Push(car1);
	stack.Push(car2);

	TextFile txtFile("file.txt");
	txtFile << stack;
	cout << "DATA FROM 'file.txt':" << endl;
	cout << txtFile;

	BinaryFile binFile("file.bin");
	stack.WriteToBinFile(binFile);
	cout << "DATA FROM 'file.bin':" << endl;
	binFile.ReadFromFile(car1);
	

	return 0;
}
