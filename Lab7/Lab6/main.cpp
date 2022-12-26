#include <iostream>

#include "Stack.h"
#include "Algorithm.h"

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
	cout << "STACK SIZE INPUT" << endl;
	int stackSize;
	TryInputData(stackSize);
	Stack<int> stack;
	for (int i = 0; i < stackSize; i++)
	{
		cout << "STACK INPUT" << endl;
		int element;
		TryInputData(element);
		stack.Push(element);
	}

	Iterator<int> iterator(stack);

	try
	{
		Algorithm<int>::PrintStack(iterator);
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	if (!Algorithm<int>::IsEmpty(iterator))
	{
		cout << "Stack is not empty!" << endl;
	}
	else
	{
		cout << "Stack is empty!" << endl;
	}

	try
	{
		cout << "Stack top is " << Algorithm<int>::Peek(iterator) << "." << endl;
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	cout << "Stack size is " << Algorithm<int>::GetStackSize(iterator) << "." << endl;

	int indexToFind;
	bool isCorrect;
	do
	{
		cout << "INDEX INPUT" << endl;
		TryInputData(indexToFind);
		try
		{
			cout << "Stack[" << indexToFind << "] is " << Algorithm<int>::GetElementOnIndex(iterator, indexToFind) << ". " << endl;
			isCorrect = true;
		}
		catch (const exception& e)
		{
			isCorrect = false;
			cout << "Error: " << e.what() << endl;
		}
	} while (!isCorrect);;

	cout << "NUMBER TO FIND IT'S INDEX INPUT" << endl;
	int numberToFind;
	TryInputData(numberToFind);
	try
	{
		int index = Algorithm<int>::GetIndexOfElement(iterator, numberToFind);
		if (index != -1)
		{
			cout << "Index of " << numberToFind << " is " << index << "." << endl;
		}
		else
		{
			cout << "There isn't " << numberToFind << " in the stack." << endl;
		}
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}
