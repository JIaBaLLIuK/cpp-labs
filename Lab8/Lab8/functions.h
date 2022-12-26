#include <stack>
#include <iostream>

using namespace std;

template <class Type>
void InputNumber(Type& number, int minValue, int maxValue)
{
	cin >> number;
	if (cin.fail() || number < minValue || number > maxValue)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		throw exception("wrong input");
	}
}

template<class Type>
void TryInputData(Type& number, int minValue = INT_MIN, int maxValue = INT_MAX)
{
	bool isCorrect;
	do
	{
		try
		{
			InputNumber(number, minValue, maxValue);
			isCorrect = true;
		}
		catch (const exception& exception)
		{
			cout << "Error: " << exception.what() << endl;
			isCorrect = false;
		}
	} while (!isCorrect);
}

template <class T>
void PushElements(stack<T>& stack)
{
	cout << "Enter amount of elements to push:" << endl;
	int elementsAmount;
	TryInputData(elementsAmount, 1);
	for (int i = 0; i < elementsAmount; i++)
	{
		T dataToPush;
		cout << "Enter data to push:" << endl;
		TryInputData(dataToPush);
		stack.push(dataToPush);
	}
}

template <class T>
void ClearStack(stack<T>& stack)
{
	while (!stack.empty())
	{
		stack.pop();
	}
}

template <class T>
void PopStack(stack<T>& stack)
{
	if (!stack.empty())
	{
		stack.pop();
	}
	else
	{
		cout << "Stack can not be popped." << endl;
	}
}

template <class T>
void GetTopElement(stack<T>& stack)
{
	if (!stack.empty())
	{
		cout << "Top element is " << stack.top() << "." << endl;
	}
	else
	{
		cout << "Stack is empty! You can not get top element!" << endl;
	}
}

template <class T>
void IsStackEmpty(stack<T>& stack)
{
	if (stack.empty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		cout << "Stack is not empty." << endl;
	}
}
