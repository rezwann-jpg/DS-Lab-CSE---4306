#include <iostream>
#include <vector>
#include <string>

struct Wizard {
    std::string name;
    int age;
    std::string house;
    int timeStamp;

    bool operator<(const Wizard& w2) const {
        if (this->age != w2.age) {
            return this->age < w2.age;
        }

        return this->timeStamp > w2.timeStamp;
    }
};

class MaxHeap {
private:
    std::vector<Wizard> heap;
    int currentTimeStamp;

    void HeapifyUp(int idx);
    void HeapifyDown(int idx);

public:
    MaxHeap() : currentTimeStamp(0) {}
    void Insert(std::string name, int age, std::string house);
    void Serve();
};

void MaxHeap::HeapifyUp(int idx) {
    if (idx == 0)
        return;

    int parent = (idx - 1) / 2;

    if (heap[idx] < heap[parent])
        return;

    std::swap(heap[idx], heap[parent]);
    HeapifyUp(parent);
}

void MaxHeap::HeapifyDown(int idx) {
    int size = heap.size();
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[largest] < heap[left])
        largest = left;

    if (right < size && heap[largest] < heap[right])
        largest = right;

    if (largest != idx) {
        std::swap(heap[idx], heap[largest]);
        HeapifyDown(largest);
    }
}

void MaxHeap::Insert(std::string name, int age, std::string house) {
    Wizard wizard = { name, age, house, currentTimeStamp++ };
    heap.push_back(wizard);
    HeapifyUp(heap.size() - 1);
}

void MaxHeap::Serve() {
    if (heap.empty()) {
        return;
    }

    Wizard wizard = heap[0];
    std::cout << "Name: " << wizard.name << ", Age: " << wizard.age << ", House: " << wizard.house << std::endl;
    heap[0] = heap.back();
    heap.pop_back();
    HeapifyDown(0);
}

int main() {
    MaxHeap pq;
    std::string command;

    while (std::getline(std::cin, command)) {
        if  (command == "X")
            break;

        if (command == "I") {
            std::string name, house;
            int age;

            std::getline(std::cin, name, ',');
            std::cin >> age;
            std::cin.ignore();
            std::getline(std::cin, house);
            pq.Insert(name, age, house);
        }
        else if (command == "S") {
            pq.Serve();
        }
    }
}