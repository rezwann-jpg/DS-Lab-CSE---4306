#include <iostream>
#include <string>

#define PRIME_NUMBER 37

struct Node {
    std::string key;
    std::string value;
    Node *next;

    Node(std::string key, std::string value) : key(key), value(value), next(nullptr) { }
};

class HashTable {
private:
    int numOfItems;
    int capacity;
    Node **arr;

    int hashFunction(const std::string& key) {
        int sum = 0;
        int factor = PRIME_NUMBER;

        for (char ch : key) {
            sum = ((sum % capacity) + (factor * ch) % capacity) % capacity;
            factor = (factor * PRIME_NUMBER) % INT16_MAX;
        }

        return sum;
    }

public:
    HashTable(int cap = 100) : numOfItems(0), capacity(cap) {
        arr = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = nullptr;
        }
    } 

    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node *curr = arr[i];
            while (curr) {
                Node *toDelete = curr;
                curr = curr->next;
                delete toDelete;
            }
        }

        delete[] arr;
    }

    void Insert(const std::string& key, const std::string& value) {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        if (arr[index] == nullptr) {
            arr[index] = newNode;
        }
        else {
            newNode->next = arr[index];
            arr[index] = newNode;
        }
        numOfItems++;
    }

    void Delete(const std::string& key) {
        int index = hashFunction(key);
        Node *currNode = arr[index];
        Node *prevNode = nullptr;

        while (currNode) {
            if (currNode->key == key) {
                if (prevNode == nullptr) {
                    arr[index] = currNode->next;
                }
                else {
                    prevNode->next = currNode->next;
                }
                delete currNode;
                numOfItems--;
                return;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
    }

    std::string Search(const std::string& key) {
        int index = hashFunction(key);
        Node *currNode = arr[index];

        while (currNode) {
            if (currNode->key == key) {
                return currNode->value;
            }
            currNode = currNode->next;
        }

        return "Not Found";
    }
};