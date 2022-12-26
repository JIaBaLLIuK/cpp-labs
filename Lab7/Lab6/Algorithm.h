#ifndef  ALGORITHM_H
#define ALGORITHM_H

#include "Stack.h"

template<class Type>
class Algorithm
{
public:
	static void PrintStack(Iterator<Type> iterator)
	{
		if (iterator.AtEnd())
		{
			throw exception("stack is empty.");
		}

		cout << "Stack elements are:" << endl;
		while (!iterator.AtEnd())
		{
			cout << *iterator << endl;
			++iterator;
		}
	}

	static bool IsEmpty(Iterator<Type> iterator)
	{
		if (iterator.AtEnd())
		{
			return true;
		}

		return false;
	}

	static Type Peek(Iterator<Type> iterator)
	{
		if (iterator.AtEnd())
		{
			throw exception("stack is empty.");
		}

		return *iterator;
	}

	static int GetStackSize(Iterator<Type> iterator)
	{
		int size = 0;
		while (!iterator.AtEnd())
		{
			size++;
			++iterator;
		}

		return size;
	}

	static Type GetElementOnIndex(Iterator<Type> iterator, int index)
	{
		if (iterator.AtEnd())
		{
			throw exception("stack is empty.");
		}

		if (index >= GetStackSize(iterator) || index < 0)
		{
			throw exception("index is out of range.");
		}

		for (int i = 0; i < index; i++)
		{
			++iterator;
		}

		return *iterator;
	}

	static int GetIndexOfElement(Iterator<Type> iterator, Type element)
	{
		if (iterator.AtEnd())
		{
			throw exception("stack is empty.");
		}

		int index = 0;
		while (!iterator.AtEnd())
		{
			if (*iterator == element)
			{
				return index;
			}

			index++;
			++iterator;
		}

		return -1;
	}
};

#endif
