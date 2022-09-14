#include <iostream>

struct Node {
	int data {};
	Node* next;

	Node (int val) {
		data = val;
		next = NULL;
	}
};

Node* ptrToHead;

void iterDisplay() {
	Node* p { ptrToHead };

	do {
		std::cout << p -> data << ' ';
		p = p -> next;
	} while (p != ptrToHead);
}

void recDisplay(Node* p, bool flag) {
	if (p != ptrToHead || !flag) {
		flag = true;
		recDisplay(p -> next, flag);
	}
}

void insertAtPos(int val, int pos) {
	Node* t { new Node(val) }, *p { ptrToHead };

	for (int i { 0 }; i < pos - 1; ++i) p = p -> next;

	t -> next = p -> next;
	p -> next = t;
}

void insertAtBeg(int val) {
	Node* t { new Node(val) };
	Node* p { ptrToHead };

	do {
		p = p -> next;
	} while (p -> next != ptrToHead);

	p -> next = t;
	t -> next = ptrToHead;
	ptrToHead = t;
}

void delAtPos(int pos) {
	Node* p { ptrToHead };

	for (int i {0}; i < pos - 2; ++i) p = p -> next;

	Node* q = p -> next;
	p -> next = q -> next;

	delete q;
}

void delHead() {
	Node* p { ptrToHead }, *q { ptrToHead };

	while (p -> next != ptrToHead) p = p -> next;

	p -> next = q -> next;
	ptrToHead = p -> next;

	delete q;
}

int main() {
	return 0;
}
