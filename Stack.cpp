#include <iostream>

/*** define ***/
struct Stack {
	int stackSize {};
	int stack[100] {};
	int top {-1};
};

/*** operations ***/

bool isStackEmpty(Stack& S) {
	return (S.top == -1) ? true : false;
}

void Push(Stack& S, int value) {
	std::cout << "Pushing...\n";
	if (S.top >= S.stackSize - 1) std::cout << "Stack Overflow.\n";
	else {
		S.stack[++S.top] = value;
		std::cout << "Pushed!\n";
	}
}

void Pop(Stack& S) {
	std::cout << "Popping...\n";
	if (isStackEmpty(S)) {
		std::cout << "Stack underflow.\n";
		return;
	}

	std::cout << "Popped!\t" << S.stack[S.top--] << '\n';
}

/*** init ***/

void programLoop(Stack& S) {
	while (1) {
		std::cout << "Enter the operation you want to perform: \n";
		std::cout << "1. Push\n2. Pop\n3. Exit\n";

		int op {};
		[[maybe_unused]] int value{};
		std::cin >> op;

		switch (op) {
			case 1:
				std::cout << "Enter the value to be pushed: ";
				std::cin >> value;
				Push(S, value);
				break;

			case 2:
				Pop(S);
				break;

			case 3:
				std::cout << "Program Exiting...\n";
				return;

			default:
				std::cout << "Please enter the correct menu values.\n";
				break;
		}
	}
}

void initStack() {
	std::cout << "Create a stack of any size (<=100)!\n";
	
	int stack_size {};
	do {
		std::cout << "Enter a valid stack size: ";
		std::cin >> stack_size;
	} while (stack_size > 100 || stack_size <= 0); 

	Stack S {stack_size, {}};
	std::cout << "Stack Initialized!\n";

	programLoop(S);
}


int main() {
	initStack();
}
