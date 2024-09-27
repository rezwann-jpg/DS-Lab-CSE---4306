#include <iostream>
#include <cstdlib>

// #define SIZE 5

class Deque {
public:
    Deque(int n);
    ~Deque();

    void push_front(int key);
    void push_back(int key);
    int pop_front();
    int pop_back();
    int size();
    int Front();
    int Rear();
    void Stat();
    void printDeque();

private:
    int* arr;
    int front, rear, capacity, currentSize;
};

Deque::Deque(int n) {
    arr = (int *)std::malloc(n * sizeof(int));
    capacity = n;
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

int Deque::Front() {
    return front;
}

int Deque::Rear() {
    return rear;
}

void Deque::Stat() {
    if (currentSize == 0) {
        std::cout << "EMPTY" << std::endl;
        return;
    }

    if (currentSize == capacity) {
        std::cout << "FULL" << std::endl;
        return;
    }

    std::cout << "NONE" << std::endl;
}

int main() {   
    int N;
    std::cin >> N;

    Deque dq(N);

    int x;
    std::string command;
    while (std::cin >> command) {
        if (command == "E")
            break;

        if (command == "PF") {
            std::cin >> x;
            dq.push_front(x);
        }
        else if (command == "PB") {
            std::cin >> x;
            dq.push_back(x);
        }
        else if (command == "DF") {
            dq.pop_front();
        }
        else if (command == "DB") {
            dq.pop_back();
        }
        else if (command == "S") {
            std::cout << dq.size() << std::endl;
        }
        else if (command == "F") {
            std::cout << dq.Front() << std::endl;
        }
        else if (command == "R") {
            std::cout << dq.Rear() << std::endl;
        }
        else if (command == "STAT") {
            dq.Stat();
        }
    }

    return 0;
}

