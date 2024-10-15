#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node (int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Deque {
private:
    Node *front;
    Node *back;
    int dequeSize;

public:
    Deque() : front(nullptr), back(nullptr), dequeSize(0) { }
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    int size();
    void printDeque();

};

void Deque::push_front(int x) {
    Node *newNode = new Node(x);

    if (!front) {
        front = newNode;
        back = newNode;
    }
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    dequeSize++;
    printDeque();
}

void Deque::push_back(int x) {
    Node *newNode = new Node(x);
    if (!back) {
        front = newNode;
        back = newNode;
    }
    else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    dequeSize++;
    printDeque();
}

void Deque::pop_front() {
    if (!front) {
        throw std::underflow_error("Deque is Empty");
    }
    Node *temp = front;
    front = front->next;
    if (front) {
        front->prev = nullptr;
    }
    else {
        back = nullptr;
    }
    delete temp;
    dequeSize--;
    printDeque();
}

void Deque::pop_back() {
    if (!back) {
        throw std::underflow_error("Deque is Empty");
    }
    Node *temp = back;
    back = back->prev;
    if (back) {
        back->next = nullptr;
    }
    else {
        front = nullptr;
    }
    delete temp;
    dequeSize--;
    printDeque();
}

int Deque::size() {
    return dequeSize;
}

void Deque::printDeque() {
    if (!front) {
        std::cout << "Deque is Empty\n";
        return;
    }
    Node *temp = front;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


int main() {
    Deque dq;

    int choice, x;
    while (true) {
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
                exit(0);
        }
    }

    return 0;
}