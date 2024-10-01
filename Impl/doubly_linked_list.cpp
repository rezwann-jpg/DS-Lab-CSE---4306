#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data; 
    Node* next; 
    Node* prev; 
  
    // Constructor to initialize Node with data
    Node(int data) : data(data), next(nullptr),
  	prev(nullptr) {}
};

// Function to traverse the doubly linked list 
// in forward direction
void forwardTraversal(Node* head) {
  
    // Start traversal from the head of the list
    Node* curr = head;

    // Continue until current node is not null
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the next node
        curr = curr->next;
    }

    // Print newline after traversal
    cout << endl;
}

// Function to traverse the doubly linked list 
// in backward direction
void backwardTraversal(Node* tail) {
  
    // Start traversal from the tail of the list
    Node* curr = tail;

    // Continue until current node is not null 
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the previous node
        curr = curr->prev;
    }

    // Print newline after traversal
    cout << endl;
}

// Function to find the length of a doubly 
//linked list
int findLength(Node * head) {
    int count = 0;
    for (Node * cur = head; cur != nullptr; cur = cur -> next)
        count++;
    return count;
}

// Insert a node at the beginning
Node* insertBegin(Node* head, int data) {
    
    // Create a new node
    Node* new_node = new Node(data);
    
    // Make next of it as head
    new_node->next = head;
    
    // Set previous of head as new node
    if (head != NULL) {
        head->prev = new_node;
    }
    
    // Return new node as new head
    return new_node;
}

// Function to insert a new node at the end of 
//doubly linked list
Node *insertEnd(Node *head, int new_data) {

    // Create a new node
    Node *new_node = new Node(new_data);

    // If the linked list is empty, set the new 
  	//node as the head of linked list
    if (head == NULL) {
        head = new_node;
    }
    else {
          Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Set the next of last node to new node
        curr->next = new_node;

        // Set prev of new node to last node
        new_node->prev = curr;
    }

    // Return the head of the doubly linked list
    return head;
}

// Function to insert a new node at a given position
Node *insertAtPosition(Node *head, int pos, int new_data) {

    // Create a new node
    Node *new_node = new Node(new_data);

    // Insertion at the beginning
    if (pos == 1) {
        new_node->next = head;

        // If the linked list is not empty, set the prev
      	//of head to new node
        if (head != NULL)
            head->prev = new_node;

        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }

    Node *curr = head;
    // Traverse the list to find the node before the
    // insertion point
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }

    // If the position is out of bounds
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete new_node;
        return head;
    }

    // Set the prev of new node to curr
    new_node->prev = curr;

    // Set the new of new node to next of curr
    new_node->next = curr->next;

    // Update the next of current node to new node
    curr->next = new_node;

    // If the new node is not the last node, update prev
 	 //of next node to new node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    // Return the head of the doubly linked list
    return head;
}

// Deletes the first node (head) of the list
// and returns the second node as new head
Node *delHead(Node *head) {

    // If empty, return
    if (head == nullptr)
        return nullptr;

    // Store in temp for deletion later
    Node *temp = head;

    // Move head to the next node
    head = head->next;

    // Set prev of the new head
    if (head != nullptr)
        head->prev = nullptr;

    // Free memory and return new head
    delete temp;
    return head;
}

// Function to delete the last node of the doubly
// linked list
Node *delLast(Node *head) {

    // Corner cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Traverse to the last node
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // Update the previous node's next pointer
    curr->prev->next = NULL;

  	// Delete the last node
    delete curr; 

    // Return the updated head
    return head;
}

// Function to delete a node at a specific position 
// in the doubly linked list
Node * delPos(Node * head, int pos) {

    // If the list is empty
    if (!head)
        return head;

    Node * curr = head;

    // Traverse to the node at the given position
    for (int i = 1; curr && i < pos; ++i) {
        curr = curr -> next;
    }

    // If the position is out of range
    if (!curr)
        return head;

    // Update the previous node's next pointer
    if (curr -> prev)
        curr -> prev -> next = curr -> next;

    // Update the next node's prev pointer
    if (curr -> next)
        curr -> next -> prev = curr -> prev;

    // If the node to be deleted is the head node
    if (head == curr)
        head = curr -> next;

    // Deallocate memory for the deleted node
    delete curr;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
  	cout << "\n";
}

int main() {
  
    // Sample usage of the doubly linked list and 
    // traversal functions
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Forward Traversal:" << endl;
    forwardTraversal(head);

    cout << "Backward Traversal:" << endl;
    backwardTraversal(third);

    return 0;
}