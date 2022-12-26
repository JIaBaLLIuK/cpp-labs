#include "functions.h"

int main()
{
	stack<int> stack;
	bool isFinished = false;
	do
	{
		int option;
		cout << "1. Push elements.\n" << "2. Pop element.\n" << "3. Get top element.\n" << "4. Get stack size.\n" << "5. Check if stack is empty.\n" << 
			"6. Clear stack.\n" << "0. Finish program." << endl;
		cout << "Choose option:" << endl;
		TryInputData(option, 0, 6);
		switch (option)
		{
		case 1:
			PushElements(stack);
			break;
		case 2:
			PopStack(stack);
			break;
		case 3:
			GetTopElement(stack);			
			break;
		case 4:
			cout << "Stack size is " << stack.size() << "." << endl;
			break;
		case 5:
			IsStackEmpty(stack);
			break;
		case 6:
			ClearStack(stack);
			break;
		case 0:
			isFinished = true;
			break;
		}
	} while (!isFinished);

	return 0;
}