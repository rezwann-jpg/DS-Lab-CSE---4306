#include <iostream>
#include <cstdlib>

#define SIZE 5

class Deque {
public:
    Deque();
    ~Deque();

    void push_front(int key);
    void push_back(int key);
    int pop_front();
    int pop_back();
    int size();
    void printDeque();

private:
    int* arr;
    int front, rear, capacity, currentSize;
};

Deque::Deque() {
    arr = (int *)std::malloc(SIZE * sizeof(int));
    capacity = SIZE;
    front = -1;
    rear = -1;
    currentSize = 0;
}

Deque::~Deque() {
    std::free(arr);
}

void Deque::push_front(int key) {
    if (currentSize == capacity) {
        std::cout << "Overflow!" << std::endl;
        return;
    }
    
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        front = (front - 1 + capacity) % capacity;
    }

    arr[front] = key;
    currentSize++;
    printDeque();
}

void Deque::push_back(int key) {
    if (currentSize == capacity) {
        std::cout << "Overflow!" << std::endl;
        return;
    }
    
    if (rear == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }

    arr[rear] = key;
    currentSize++;
    printDeque();
}

int Deque::pop_front() {
    if (currentSize == 0) {
        std::cout << "Underflow!" << std::endl;
        return -1;
    }

    int result = arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }

    currentSize--;
    printDeque();
    return result;
}

int Deque::pop_back() {
    if (currentSize == 0) {
        std::cout << "Underflow!" << std::endl;
        return -1;
    }

    int result = arr[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity;
    }

    currentSize--;
    printDeque();
    return result;
}

int Deque::size() {
    return currentSize;
}

void Deque::printDeque() {
    if (currentSize == 0) {
        std::cout << "Deque is empty" << std::endl;
        return;
    }
    
    for (int i = 0; i < currentSize; i++) {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

int main() {    
    Deque dq;

    while (true) {
        int choice, x;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin >> x;
                dq.push_front(x);
                break;
            case 2:
                std::cin >> x;
                dq.push_back(x);
                break;
            case 3:
                dq.pop_front();
                break;
            case 4:
                dq.pop_back();
                break;
            case 5:
                std::cout << dq.size() << std::endl;
                break;
            case 6:
                exit(EXIT_SUCCESS);
        }
    }

    return 0;
}
