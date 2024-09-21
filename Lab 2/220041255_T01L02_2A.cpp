#include <iostream>
#include <cstdlib>

class Queue {
public:
	Queue(int n);
	~Queue();

	void EnQueue(int x);
	void DeQueue();
	bool isEmpty();
	bool isFull();
	int Size();
	int Front();
	void PrintQueue();

private:
	int *circArr;
	int size;
	int capacity;
	int front;
	int rear;
};

Queue::Queue(int n) {
	circArr = (int *)std::malloc(n * sizeof(int));
	capacity = n;
	size = 0;
	front = -1;
	rear = -1;
}

Queue::~Queue() {
	std::free(circArr);
}

void Queue::EnQueue(int x) {
    if (isEmpty()) {
        front = 0;
    }

	if (isFull()) {
		std::cout << "Overflow" << std::endl;
		return;
	}
	else {
        rear = (rear + 1) % capacity;
        circArr[rear] = x;
        size++;
	}
}

void Queue::DeQueue () {
	if (isEmpty()) {
		std::cout << "Underflow" << std::endl;
		return;
	}
	else {
		front = (front + 1) % capacity;
		size--;
	}
}

bool Queue::isEmpty() {
	return size == 0;
}

bool Queue::isFull() {
	return size == capacity;
}

int Queue::Size() {
	return size;
}

int Queue::Front() {
	if (isEmpty()) {
		std::cout << "Underflow" << std::endl;
		return 0;
	}
	return circArr[front];
}

void Queue::PrintQueue() {
    if (isEmpty()) {
        return;
    }
    for (int i = 0; i < size; i++) {
		int index = (front + i) % capacity;
        std::cout << circArr[index] << " ";
    }
	std::cout << std::endl;
}

int main() {
	int N;
	std::cin >> N;

	Queue q(N);

	while (true) {
		int choice;
		int x;
		std::cin >> choice;

		switch (choice) {
			case 1:
				std::cin >> x;
				q.EnQueue(x);
				std::cout << "EnQueue: ";
				q.PrintQueue();
				break;

            case 2:
				q.DeQueue();
				std::cout << "DeQueue: ";
				q.PrintQueue();
				break;

			case 3:
				std::cout << "isEmpty: " << (q.isEmpty() ? "True" : "False") << std::endl;
				break;

			case 4:
				std::cout << "isFull: " << (q.isFull() ? "True" : "False") << std::endl;
				break;

			case 5:
				std::cout << "Size: " << q.Size() << std::endl;
				break;

			case 6:
				std::cout << "Front: " << q.Front() << std::endl;
				break;

			case -1:
				exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
