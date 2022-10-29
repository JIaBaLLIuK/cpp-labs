#include <iostream>

using namespace std;

template <class Type>
class Stack
{
public:
	struct Node
	{
		Type data;
		Node* next = nullptr;
		explicit Node(Type);
		~Node() = default;
	};

	Stack() = default;
	~Stack() = default;
	void Push(Type);
	Type Pop();
	bool IsEmpty() const;
	void PrintStack() const;
	void DeleteStack();
	Type Peek();

private:
	Node* _top = nullptr;
};

template <class Type>
Stack<Type>::Node::Node(Type data) : data(data)
{ }

template<class Type>
void Stack<Type>::Push(Type data)
{
	auto* temp = new Node(data);
	temp->next = _top;
	_top = temp;
}

template<class Type>
Type Stack<Type>::Pop()
{
	Type poppedElement = 0;
	if (!_top)
	{
		cout << "Stack is empty! It can not be popped!" << endl;
	}
	else
	{
		poppedElement = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
	}
	
	return poppedElement;
}

template<class Type>
bool Stack<Type>::IsEmpty() const
{
	return _top == nullptr;
}

template<class Type>
void Stack<Type>::PrintStack() const
{
	Node* temp = _top;
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

int main()
{
	Stack<int> stack;
	for (int i = 1; i <= 5; i++)
	{
		stack.Push(i);
	}

	cout << "Now stack looks like:" << endl;
	stack.PrintStack();
	cout << "Stack after pop looks like:" << endl;
	int poppedElement = stack.Pop();
	stack.PrintStack();
	cout << "Popped element is " << poppedElement << "." << endl;
	cout << "Element on the top is " << stack.Peek() << "." << endl;
	if (stack.IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		cout << "Stack is not empty." << endl;
	}
	
	stack.DeleteStack();
	cout << "Stack deleting..." << endl;
	stack.PrintStack();
	return 0;
}
