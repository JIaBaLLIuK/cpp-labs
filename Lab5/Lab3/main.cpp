#include <iostream>
#include "Exception.h"
#include "Car.h"

using namespace std;

template <class Type>
void InputNumber(Type&);

template <class Type>
void InputData(Type&);

int main()
{
	Car tesla("tesla");
	tesla.SetColor("black");
	bool isCorrect;

	cout << "NUMBER OF DOORS INPUT" << endl;
	int doorsAmount;
	do
	{
		try
		{
			InputData(doorsAmount);
			tesla.SetDoorsAmount(doorsAmount);
			isCorrect = true;
		}
		catch (ArgumentOutOfRangeException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
			cout << "Wrong data: " << exception.GetWrongData() << endl;
		}
	} while (!isCorrect);

	cout << "CAR LENGTH INPUT" << endl;
	int carLength;
	do
	{
		try
		{
			InputData(carLength);
			tesla.SetLength(carLength);
			isCorrect = true;
		}
		catch (ArgumentOutOfRangeException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
			cout << "Wrong data: " << exception.GetWrongData() << endl;
		}
	} while (!isCorrect);

	cout << "CAR WIDTH INPUT" << endl;
	int carWidth;
	do
	{
		try
		{
			InputData(carWidth);
			tesla.SetWidth(carWidth);
			isCorrect = true;
		}
		catch (ArgumentOutOfRangeException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
			cout << "Wrong data: " << exception.GetWrongData() << endl;
		}
	} while (!isCorrect);

	cout << "CAR HEIGHT INPUT" << endl;
	int carHeight;
	do
	{
		try
		{
			InputData(carHeight);
			tesla.SetHeight(carHeight);
			isCorrect = true;
		}
		catch (ArgumentOutOfRangeException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
			cout << "Wrong data: " << exception.GetWrongData() << endl;
		}
	} while (!isCorrect);

	cout << "ENGINE POWER INPUT" << endl;
	int enginePower;
	do
	{
		try
		{
			InputData(enginePower);
			tesla.SetPower(enginePower);
			isCorrect = true;
		}
		catch (ArgumentOutOfRangeException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
			cout << "Wrong data: " << exception.GetWrongData() << endl;
		}
	} while (!isCorrect);

	tesla.SetType(EngineType::electricEngine);
	tesla.SetVolume(0.f);
	tesla.GetCarInformation();
	return 0;
}

template <class Type>
void InputNumber(Type& number)
{
	cout << "Enter the number:" << endl;
	cin >> number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		throw ArgumentException<int>("wrong input", number, 1);
	}
}

template <class Type>
void InputData(Type& number)
{
	bool isCorrect;
	do
	{
		try
		{
			InputNumber(number);
			isCorrect = true;
		}
		catch (ArgumentException<int>& exception)
		{
			isCorrect = false;
			cout << "Error message: " << exception.what() << endl;
			cout << "Error code: " << exception.GetErrorCode() << endl;
		}
	} while (!isCorrect);
}
