#ifndef  STACK_H
#define STACK_H

#include <iostream>

#include "BinaryFile.h"

using namespace std;

template <class Type>
class Node
{
public:
	Type data;
	Node* next = nullptr;
	explicit Node(Type);
	~Node() = default;
};

template <class Type>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;
	void Push(Type);
	void Pop();
	bool IsEmpty() const;
	void PrintStack() const;
	void DeleteStack();
	Type Peek();
	void WriteToBinFile(BinaryFile&);

	template <class Type>
	friend ofstream& operator << (ofstream&, Stack<Type>&);

private:
	Node<Type>* _top = nullptr;
};

template <class Type>
ofstream& operator << (ofstream& file, Stack<Type>& stack)
{
	Node<Type>* temp = stack._top;
	if (!temp)
	{
		cout << "Stack is empty!" << endl;
	}
	else
	{
		do
		{
			file << temp->data << endl;
			temp = temp->next;
		} while (temp);
	}

	return file;
}

template <class Type>
Node<Type>::Node(Type data) : data(data)
{ }

template<class Type>
void Stack<Type>::Push(Type data)
{
	auto* temp = new Node<Type>(data);
	temp->next = _top;
	_top = temp;
}

template<class Type>
void Stack<Type>::Pop()
{
	if (!_top)
	{
		cout << "Stack is empty! It can not be popped!" << endl;
	}
	else
	{
		Node* temp = _top;
		_top = _top->next;
		delete temp;
	}
}

template<class Type>
bool Stack<Type>::IsEmpty() const
{
	return _top == nullptr;
}

template<class Type>
void Stack<Type>::PrintStack() const
{
	Node<Type>* temp = _top;
	if (!temp)
	{
		cout << "Stack is empty! It can not be printed!" << endl;
	}
	else
	{
		do
		{
			cout << temp->data << endl;
			temp = temp->next;
		} while (temp);
	}
}

template<class Type>
void Stack<Type>::DeleteStack()
{
	if (!_top)
	{
		cout << "Stack is empty! It can not be printed!" << endl;
	}
	else
	{
		do
		{
			Pop();
		} while (_top);
	}
}

template<class Type>
Type Stack<Type>::Peek()
{
	return _top->data;
}

template<class Type>
void Stack<Type>::WriteToBinFile(BinaryFile& file)
{
	Node<Type>* temp = _top;
	if (!temp)
	{
		cout << "Stack is empty! It can not be written to a file!" << endl;
	}
	else
	{
		do
		{
			file.WriteToFile(temp->data);
			temp = temp->next;
		} while (temp);
	}
}

#endif
