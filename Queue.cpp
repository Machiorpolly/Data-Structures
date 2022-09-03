#include <iostream>

/*** define ***/

struct Queue {
	int queueSize {};
	int queue[100] {};
	int head {-1};
	int tail {-1};
};

/*** operations ***/

bool isEmpty(Queue& Q) {
	return ((Q.head == -1 && Q.tail == -1) ? true : false);
}

bool isFull(Queue& Q) {
	return (((Q.head)%Q.queueSize == (Q.tail + 1)%Q.queueSize) ? true : false);
}

void Enqueue(Queue& Q, int value) {
	std::cout << "Inserting...\n";

	if (isFull(Q)) {
		std::cout << "Queue is full!\n";
		return;
	}
	else if (isEmpty(Q)) {
		Q.tail = Q.head = 0;
	}
	else {
		Q.tail = (Q.tail + 1)%Q.queueSize;
	}

	Q.queue[Q.tail] = value;
	std::cout << "Inserted!\n";

	return;
}

void Dequeue(Queue& Q) {
	std::cout << "Deleting...\n";
	int deleted {};
	if (isEmpty(Q)) {
		std::cout << "Queue is empty!\n";
		return;
	}
	else if (Q.head == Q.tail) {
		deleted = Q.queue[Q.head];
		Q.tail = Q.head = -1;
	}
	else {
		deleted = Q.queue[Q.head];
		Q.head = (Q.head + 1)%Q.queueSize;
	}

	std::cout << "Deleted!\t" << deleted << '\n';
}

/*** init ***/

void programLoop(Queue& Q) {
	while (1) {
		std::cout << "Enter the operation you want to perform.\n";
		std::cout << "1. Enqueue\n2. Dequeue\n3. Exit\n";

		int op {};
		[[maybe_unused]] int value {};
		std::cin >> op;

		switch(op) {
			case 1:
				std::cout << "Enter the value to be inserted: ";
				std::cin >> value;
				Enqueue(Q, value);
				break;

			case 2:
				Dequeue(Q);
				break;

			case 3:
				std::cout << "Exiting...\n";
				return;

			default:
				std::cout << "Please enter correct menu values.\n";
				break;
		}

		//std::cout << Q.head << '\t' << Q.tail << '\t' << Q.queueSize << '\n';
	}
}

void init() {
	std::cout << "Create a queue of any size (<= 100)!\n";
	int queue_size {};

	do {
		std::cout << "Enter a valid queue size: ";
		std::cin >> queue_size;
	} while (queue_size > 100 || queue_size <= 0);

	Queue Q {queue_size, {}};
	programLoop(Q);
}

int main() {
	init();
}