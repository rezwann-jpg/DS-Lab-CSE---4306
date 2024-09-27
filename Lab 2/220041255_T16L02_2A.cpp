#include <iostream>
#include <cstdlib>
#include <string>

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
    int Rear();

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
		std::cout << "Overflow!!" << std::endl;
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
		std::cout << "Underflow!!" << std::endl;
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

int Queue::Rear() {
    if (isEmpty()) {
		std::cout << "Underflow" << std::endl;
		return 0;
	}
	return circArr[rear];
}

void Queue::PrintQueue() {
    std::cout << "Current Size : " << Size() << std::endl;
    std::cout << "Full? " << (isFull() ? "Yes" : "No") << std::endl;
    std::cout << "Empty? " << (isEmpty() ? "Yes" : "No") << std::endl;
    if (!isEmpty()) {
            std::cout << "Front Element : " << Front() << std::endl;
            std::cout << "Front Index : " << front << std::endl;
            std::cout << "Rear Element : " << Rear() << std::endl;
            std::cout << "Rear Index : " << rear << std::endl;
        }
        else {
            std::cout << "Front Element : -" << std::endl;
            std::cout << "Front Index : 0" << std::endl;
            std::cout << "Rear Element : -" << std::endl;
            std::cout << "Rear Index : 0" << std::endl;
        }

        std::cout << "Queue Elements : ";
        if (!isEmpty()) {
            int i = front;
            for (int count = 0; count < size; count++) {
                std::cout << circArr[i] << (count < size - 1 ? " " : "");
                i = (i + 1) % capacity;
            }
        } else {
            std::cout << "-";
        }
        std::cout << std::endl;
}

int main() {
	int N;
	std::cin >> N;

	Queue q(N);

    std::string command;
    while (std::cin >> command) {
        if (command == "-1") 
            break;

        if (command == "E") {
            int x;
            std::cin >> x;
            q.EnQueue(x);
            q.PrintQueue();
        }
        else if (command == "D") {
            q.DeQueue();
            q.PrintQueue();
        }
    }

	return 0;
}