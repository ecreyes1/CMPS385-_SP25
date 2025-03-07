#include <iostream>
#include <stack>

using namespace std;
void printStackElements(stack<int> stack) {
	while (!stack.empty())
	{
		//retrives elements from the stack
		cout << stack.top() << endl;
		stack.pop();
	}

}
int main()
{
	//empty size, push pop,top
	stack<int>numbersStack;
	numbersStack.push(1);
	numbersStack.push(2);
	numbersStack.push(3);
	cout << "Elements pushed into the stack:" << endl;
	printStackElements(numbersStack);
	cout << "Elements remaining after:" << endl;
	numbersStack.pop();
	printStackElements(numbersStack);
	

	return 0;
}