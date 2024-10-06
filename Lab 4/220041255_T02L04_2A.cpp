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

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void Insert_front(int key);
    void Insert_back(int key);
    void Insert_after_node(int key, int v);
    void Update_node(int key, int v);
    void Remove_head();
    void Remove_element(int key);
    void Remove_end();
    void Display();
};

void LinkedList::Insert_front(int key) {
    Node *newNode = new Node(key);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::Insert_back(int key) {
    Node *newNode = new Node(key);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
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
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        temp->next = newNode;
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

    if (temp) {
        temp->data = key;
    }
    else {
        std::cout << "Value not found\n";
    }
}

void LinkedList::Remove_head() {
    if (!head) {
        std::cout << "Underflow\n";
    }
    else {
        Node *temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
}

void LinkedList::Remove_element(int key) {
    if (!head) {
        std::cout << "Underflow\n";
        return;
    }
    
    Node *temp = head;
    while (temp && temp->data != key) {
        temp = temp->next;
    }
    if (temp) {
        if (temp == head) {
            Remove_head();
            return;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }
    else {
        std::cout << "Value not found\n";
    }
}

void LinkedList::Remove_end() {
    if (!head) {
        std::cout << "Underflow\n";
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void LinkedList::Display() {
    if (!head) {
        std::cout << "Empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        if (temp == head)
            std::cout << temp->data << " (HEAD)";
        else if (temp == tail) 
            std::cout << " -> " << temp->data << " (TAIL)";
        else 
            std::cout << " -> " << temp->data;
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList l1;
    std::string command;
    int key, value;

    while (true) {
        std::cin >> command;
        if (command == "INSERT_FRONT") {
            std::cin >> key;
            l1.Insert_front(key);
            l1.Display();
        }
        else if (command == "INSERT_BACK") {
            std::cin >> key;
            l1.Insert_back(key);
            l1.Display();
        }
        else if (command == "INSERT_AFTER") {
            std::cin >> key >> value;
            l1.Insert_after_node(key, value);
            l1.Display();
        }
        else if (command == "UPDATE") {
            std::cin >> key >> value;
            l1.Update_node(key, value);
            l1.Display();
        }
        else if (command == "REMOVE_HEAD") {
            l1.Remove_head();
            l1.Display();
        }
        else if (command == "REMOVE") {
            std::cin >> key;
            l1.Remove_element(key);
            l1.Display();
        }
        else if (command == "REMOVE_TAIL") {
            l1.Remove_end();
            l1.Display();
        }
        else if (command == "EXIT") {
            break;
        }
    }
    
    return 0;
}