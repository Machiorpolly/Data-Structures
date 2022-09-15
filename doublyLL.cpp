#include <iostream>

struct Node {
	int data {};
	Node* next;
	Node* prev;

	Node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};

Node* head { new Node(0) };

void create(int arr[], int n) {
	Node* t, *last;

	head -> data = arr[0];
	last = head;
	
	for (int i { 1 }; i < n; ++i) {
		t = new Node(arr[i]);
		t -> next = last -> next;
		t -> prev = last;
		last -> next = t;
		last = t;
	}
}

void display() {
	Node* p { head };

	while (p != NULL) {
		std::cout << p -> data << ' ';
		p = p -> next;
	}
	std::cout << '\n';
}

void insertAtPos(int val, int pos) {
	Node* t { new Node(val) };

	Node* p { head };
	
	for (int i {0}; i < pos - 1; i++) p = p -> next;

	t -> prev = p;
	t -> next = p -> next;
	(p -> next) -> prev = t;
	p -> next = t;
}

void insertBeforeHead(int val) {
	Node* t { new Node(val) };

	head -> prev = t;

	t -> next = head;

	head = t;
}

void delAtPos(int pos) {
	Node* p { head };

	for (int i {0}; i < pos - 1; ++i) p = p -> next;

	(p -> prev) -> next = p -> next;
	if (p -> next) (p -> next) -> prev = p -> prev;

	delete p;
}

void delHead() {
	Node* p { head };

	head = head -> next;

	delete p;

	if (head) head -> prev = NULL;
}

int main()
{
	return 0;
}
