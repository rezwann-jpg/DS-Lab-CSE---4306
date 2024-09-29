#include <iostream>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node *head;

public:
    LinkedList();
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);
    void display();
};

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertAtBeginning(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // if the list is empty
    if (!head) {
        head = newNode;
        return;
    }

    // traverse
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::insertAtPosition(int value, int position) {
    if (position < 1) {
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;

    // Traverse to the node before the position
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }  

    if (!temp) {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteFromBeginning() {
    if (!head) {
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {
    if (!head) {
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::deleteFromPosition(int position) {
    if (position < 1) {
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void LinkedList::display() {
    if (!head) {
        return;
    }

    Node *temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL";
    std::cout << std::endl;
}

int main() {
    LinkedList l1;

    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);

    l1.insertAtBeginning(5);
    l1.insertAtBeginning(6);

    l1.insertAtPosition(40, 5);

    l1.display();

    return 0;
}