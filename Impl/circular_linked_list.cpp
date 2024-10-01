#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

// Function to insert a node into an empty circular singly linked list
Node *insertInEmptyList(Node *last, int data){
    if (last != nullptr) return last;
    
    // Create a new node
    Node *newNode = new Node(data);
  
    // Point newNode to itself
    newNode->next = newNode;
  
    // Update last to point to the new node
    last = newNode;
    return last;
}

// Function to insert a node at the beginning of the
// circular linked list
Node* insertAtBeginning(Node* last, int value){
    // Allocate memory for the new node and set its data
    Node* newNode = new Node(value);

    // If the list is empty, make the new node point to
    // itself and set it as last
    if (last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    // Insert the new node at the beginning
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

// Function to insert a node at the end of a circular linked list
Node *insertEnd(Node *tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == nullptr){
        // If the list is empty, initialize it with the new node
        tail = newNode;

        // Point to itself to form a circular structure
        newNode->next = newNode;
    }
    else{
        // Insert new node after the current tail
        // and update the tail pointer.
        // New node points to the head node
        newNode->next = tail->next;

        // Tail node points to the new node
        tail->next = newNode;

        // Update tail to be the new node
        tail = newNode;
    }
    return tail;
}

// Function to insert a node at a specific position in a circular linked list
Node *insertAtPosition(Node *last, int data, int pos){
    if (last == nullptr){
        // If the list is empty
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return last;
        }
        // Create a new node and make it point to itself
        Node *newNode = new Node(data);
        last = newNode;
        last->next = last;
        return last;
    }

    // Create a new node with the given data
    Node *newNode = new Node(data);

    // curr will point to head initially
    Node *curr = last->next;

    if (pos == 1){
        // Insert at the beginning
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    // Traverse the list to find the insertion point
    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;
      
        // If position is out of bounds
        if (curr == last->next){
            cout << "Invalid position!" << endl;
            return last;
        }
    }
    // Insert the new node at the desired position
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end
    if (curr == last) last = newNode;

    return last;
}

// Function to delete the first node of the circular linked list
Node* deleteFirstNode(Node* last) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty" << endl;
        return nullptr;
    }

    Node* head = last->next;

    if (head == last) {
        // If there is only one node in the list
        delete head;
        last = nullptr;
    } else {
        // More than one node in the list
        last->next = head->next;
        delete head;
    }

    return last;
}

// Function to delete a specific node in the circular linked list
Node* deleteSpecificNode(Node* last, int key) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }

    Node* curr = last->next;
    Node* prev = last;

    // If the node to be deleted is the only node in the list
    if (curr == last && curr->data == key) {
        delete curr;
        last = nullptr;
        return last;
    }

    // If the node to be deleted is the first node
    if (curr->data == key) {
        last->next = curr->next;
        delete curr;
        return last;
    }

    // Traverse the list to find the node to be deleted
    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is found
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        delete curr;
    } else {
        // If the node to be deleted is not found
        cout << "Node with data " << key
          << " not found." << endl;
    }

    return last;
}

// Function to delete the last node in the circular linked list
Node* deleteLastNode(Node* last) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }
    Node* head = last->next;

    // If there is only one node in the list
    if (head == last) {
        delete last;
        last = nullptr;
        return last;
    }
    // Traverse the list to find the second last node
    Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }
    // Update the second last node's next pointer
    // to point to head
    curr->next = head;
    delete last;
    last = curr;

    return last;
}

// Function to search for a specific value in the
// circular linked list
bool search(Node* last, int key) {
    if (last == nullptr) {
        // If the list is empty
        return false;
    }

    Node* head = last->next;
    Node* curr = head;

    // Traverse the list to find the key
    while (curr != last) {
        if (curr->data == key) {
          // Key found
            return true; 
        }
        curr = curr->next;
    }

    // Check the last node
    if (last->data == key) {
      // Key found
        return true; 
    }
    // Key not found
    return false; 
}

void printList(Node *last){
    if (last == NULL) return;

    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}


void printList(Node* last){
    if(last == NULL) return;
  
    // Start from the head node
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

int main(){
    Node *last = nullptr;

    // Insert a node into the empty list
    last = insertInEmptyList(last, 1);

    // Print the list
    cout << "List after insertion: ";
    printList(last);

    return 0;
}