#include <iostream>

struct Node {
    int data;
    Node *next;

    Node (int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) { }

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
    LinkedList l1;
    int num;

    while (std::cin >> num && num != -1) {
        l1.insert(num);
    }

    Node *odd = l1.getHead();
    Node *even = l1.getHead()->next;
    Node *even_start = l1.getHead()->next;

    while (odd->next && even->next) {
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start;

    l1.print_list();
}

int main() {
    Solve();

    return 0;
}