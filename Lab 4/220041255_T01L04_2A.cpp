#include <iostream>
#include <cstdlib>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
public:
    LinkedList();
    void Insert_front(int x);
    void Insert_back(int x);
    void Insert_after_node(int key, int v);
    void Update_node(int key, int v);
    void Remove_head();
    void Remove_element(int key);
    void Remove_end();
    void Display();
};

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::Insert_front(int x) {
	Node *newNode = new Node(x);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::Insert_back(int x) {
	Node *newNode = new Node(x);

	if (!head) {
		head = newNode;
        tail = newNode;
	}
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::Insert_after_node(int key, int v) {
    Node *temp = head;

    while (temp && temp->data != v) {
        temp = temp->next;
    }
    if (temp) {
        Node *newNode = new Node(key);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }
    else {
        std::cout << "Value not found\n"; 
    }
}

void LinkedList::Update_node(int key, int v) {
    Node *temp = head;

    while (temp && temp->data != v) {
        temp = temp->next;
    }

    if (!temp) {
        std::cout << "Value Not Found\n" << std::endl;
    }
    else {
        temp->data = key;
    }
}

void LinkedList::Remove_head() {
    if (!head) {
        std::cout << "Underflow" << std::endl;
    }
    else {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::Remove_element(int key) {
    if (!head) {
        std::cout << "Underflow" << std::endl;
        return;
    }

    if (head->data == key) {
        Remove_head();
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp;
    }
    else {
        std::cout << "Value Not Found\n" << std::endl;
    }
}

void LinkedList::Remove_end() {
    if (!head) {
        std::cout << "Underflow" << std::endl;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}

void LinkedList::Display() {
    if (!head) {
        std::cout << "Head=Null, Tail=Null, Empty" << std::endl;
        return;
    }

    Node *temp = head;
    std :: cout << "Head=" << head->data << ", Tail=" << tail->data << ", ";
    while (temp) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


int main() {
    int choice, x, k;
    LinkedList l1;

    while (true) {
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin >> x;
            l1.Insert_front(x);
            l1.Display();
            break;
        case 2:
            std::cin >> x;
            l1.Insert_back(x);
            l1.Display();
            break;
        case 3:
            std::cin >> x >> k;
            l1.Insert_after_node(x, k);
            l1.Display();
            break;
        case 4:
            std::cin >> x >> k;
            l1.Update_node(x, k);
            l1.Display();
            break;
        case 5:
            l1.Remove_head();
            l1.Display();
            break;
        case 6:
            std::cin >> x;
            l1.Remove_element(x);
            l1.Display();
            break;
        case 7:
            l1.Remove_end();
            l1.Display();
            break;
        case 8:
            exit(0);
        }
    }

    return 0;
}
