#include <iostream>

struct Node {
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

public:

    LinkedList() : head(nullptr) {}

    void insert(int key) {
        Node *newNode = new Node(key);
        if (!head) {
            head = newNode;
        }
        else {
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node *getHead() { return head; }

    void print_list() {
        if (!head) {
            std::cout << "Empty\n";
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

void Solve() {
    LinkedList l1, l2;
    int value;

    while (std::cin >> value && value != -1) {
        l1.insert(value);
    }

    // l1.print_list();

    while (std::cin >> value && value != -1) {
        l2.insert(value);
    }

    // l2.print_list();

    Node *head1 = l1.getHead();
    Node *head2 = l2.getHead();
    LinkedList result;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            result.insert(head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
        // result.print_list();
    }

    result.print_list();
}

int main() {
    Solve();
    return 0;
}