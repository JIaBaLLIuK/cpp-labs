#ifndef  STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class Type>
class Stack;

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
class Iterator
{
public:
	Iterator(Stack<Type>);
	~Iterator() = default;
	Iterator<Type>& operator++();
	Type& operator*() const;
	bool AtEnd() const;

private:
	Node<Type>* currentNode;
};

template <class Type>
Iterator<Type>::Iterator(Stack<Type> stack) : currentNode(stack._top)
{ }

template <class Type>
Iterator<Type>& Iterator<Type>::operator++()
{

	this->currentNode = this->currentNode->next;
	return *this;
}

template <class Type>
Type& Iterator<Type>::operator*() const
{
	return currentNode->data;
}

template<class Type>
bool Iterator<Type>::AtEnd() const
{
	if (!currentNode)
	{
		return true;
	}

	return false;
}

template <class Type>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;
	void Push(Type);
	void Pop();
	void DeleteStack();
	friend class Iterator<Type>;

private:
	Node<Type>* _top = nullptr;
};

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
		Node<Type>* temp = _top;
		_top = _top->next;
		delete temp;
	}
}

template<class Type>
void Stack<Type>::DeleteStack()
{
	if (!_top)
	{
		cout << "Stack is empty! It can not be deleted!" << endl;
	}
	else
	{
		do
		{
			Pop();
		} while (_top);
	}
}

#endif
