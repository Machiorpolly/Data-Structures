#include <iostream>

struct Node {
	int data;
	Node* next;

	Node (int value) {
		data = value;
		next = NULL;
	}
};

Node* ptrToHead;

void init() {
	std::cout << "Enter a value to initialize the Linked List: ";
	int value {};
	std::cin >> value;

	ptrToHead = new Node(value);

	std::cout << "Linked List is initialized!\n";
	
	programLoop();
	return;
}

void printList() {
	Node* temp = ptrToHead;

	while (temp != NULL) {
		std::cout << temp -> data << " -> ";
		temp = temp -> next;
	}

	std::cout << "NULL\n";

	return;
}

void recPrintList(Node* temp) {
	if (temp == NULL) {
		std::cout << "NULL\n";
		return;
	}

	while (temp != NULL) {
		recPrintList(temp -> next);
		std::cout << temp -> data << " -> ";
	}
}

void insertAtBeg() {
	std::cout << "Enter a value: ";
	int value{};
	std::cin >> value;

	Node* temp = new Node(value);
	temp -> next = ptrToHead;

	ptrToHead = temp;

	temp = NULL;

	std::cout << "Element inserted!\n";
	return;
}

void insertAtEnd() {
	std::cout << "Enter a value: ";
	int value {};
	std::cin >> value;

	Node* temp1 = new Node(value);

	Node* temp2 = ptrToHead;

	while (temp2 != NULL) {
		temp2 = temp2 -> next;
	}

	temp2 -> next = temp1;

	temp1 = temp2 = NULL;
	
	std::cout << "Element inserted!\n";
	return;
}

void insertAtAnyPos() {
	std::cout << "Enter the position to insert the element (Element will be added after the position): ";

	int pos {};
	std::cin >> pos;

	std::cout << "Enter value: ";
	int value {};
	std::cin >> value;

	Node* temp = new Node(value);

	--pos;

	Node* p = ptrToHead;
	while (pos--) {
		p = p -> next;
	}

	temp -> next = p -> next;
	p -> next = temp;

	temp = NULL;

	std::cout << "Element inserted!\n";

	return;
}


void searchList() {
	std::cout << "Enter the value to be searched: ";

	int value {};
	std::cin >> value;

	Node* temp = ptrToHead;

	while (temp != NULL) {
		if (value == temp -> data) {
			std::cout << "Element found!\n";
			return;
		}
		temp = temp -> next;
	}
	
	std::cout << "Element not found!\n";
	return;
}

void deleteHeadNode() {
	Node* p = ptrToHead;

	ptrToHead = ptrToHead -> next;

	delete p;
}

void programLoop() {
	while (1) {
		std::cout << "Choose any one of the options.\n";
		std::cout << "1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Print the list\n5. Search in the list\n";
		std::cout << "6. Exit\n";

		int ch {};
		std::cin >> ch;

		switch (ch) {

			case 1:
				insertAtBeg();
				break;

			case 2:
				insertAtEnd();
				break;

			case 3:
				insertAtAnyPos();
				break;

			case 4:
				printList();
				break;

			case 5:
				searchList();
				break;

			case 6:
				std::cout << "Program exiting...\n";
				return;
				break;

			default:
				std::cout << "Enter a valid option!\n";
				break;
		}
	}
}

int main() {
	init();

	return 0;
}
