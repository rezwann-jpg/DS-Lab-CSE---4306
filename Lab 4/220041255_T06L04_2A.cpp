#include <iostream>
#include <cstdlib>
#include <climits>

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack {
    Node* head;
    int count;
    int stackSize;

public:
    Stack(int n) : head(nullptr), count(0), stackSize(n) {}

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull () {
        return count == stackSize;
    }

    int Size () {
        return count;
    }

    void push(int new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
        count++;
    }

    void pop() {
        if (this->isEmpty()) {
            std::cout << "\nUnderflow" << std::endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top() {
        if (!isEmpty())
            return head->data;
        else {
            std::cout << "\nStack is empty";
            return INT_MIN;
        }
    }

    void display() {
        if (!head) {
            return;
        }

        Node *temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int N;
    std::cin >> N;

    Stack s1(N);

    while (true) {
        int choice, x;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin >> x;
            s1.push(x);
            s1.display();
            break;
        case 2:
            s1.pop();
            s1.display();
            break;
        case 3:
            std::cout << (s1.isEmpty() ? "True" : "False") << std::endl;
            break;
        case 4:
            std::cout << (s1.isFull() ? "True" : "False") << std::endl;
            break;
        case 5:
            std::cout << s1.Size() << std::endl;
            break;
        case 6:
            std::cout << s1.top() << std::endl;
            break;
        case -1:
            exit(0);
        }
    }

    return 0;
}
