#include <iostream>
#include <vector>
#include <cstdlib>

class Heap {
public:
    void insert(int key);
    void printHeap();
    int heap_max() {
        return heap[0];
    }
    int heap_extract_max();
    void max_heap_insert(int key);
    void heap_decrease_key(int i, int value);
    void heap_increase_key(int i, int value);
    void build_max_heap();
private:
    void max_heapify(int i, int n);

    std::vector<int> heap;
};

void Heap::insert(int key) {
    heap.push_back(key);
}

void Heap::printHeap() {
    for (int i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::max_heapify(int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = n;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        max_heapify(largest, n);
    }
}

void Heap::build_max_heap() {
    int N = heap.size();

    int startIdx = (N / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        max_heapify(i, N);
    }
}

int Heap::heap_extract_max() {
    if (heap.size() == 1) {
        return heap[0];
        heap.pop_back();
    }

    int root = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    max_heapify(0, heap.size());

    return root;
}

void Heap::max_heap_insert(int key) {
    heap.push_back(key);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1)/ 2] < heap[i]) {
        std::swap(heap[i], heap[(i - 1)/ 2]);
        i = (i - 1)/ 2;
    }
}

void Heap::heap_decrease_key(int i, int value) {
    heap[i] -= value;

    max_heapify(i, heap.size());
}

void Heap::heap_increase_key(int i, int value) {
    heap[i] += value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        std::swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

int main() {
    Heap h1;

    int num;
    while (std::cin >> num) {
        if (num == -1)
            break;

        h1.insert(num);
    }

    h1.build_max_heap();
    std::cout << "Min Heap: ";
    h1.printHeap();

    while (true) {
        int choice, k, i, val;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << h1.heap_max() << std::endl;
            h1.printHeap();
            break;

        case 2:
            std::cout << h1.heap_extract_max() << std::endl;
            h1.printHeap();
            break;

        case 3:
            std::cin >> k;
            h1.max_heap_insert(k);
            h1.printHeap();
            break;

        case 4:
            std::cin >> i >> val;
            h1.heap_decrease_key(i - 1, val);
            h1.printHeap();
            break;

        case 5:
            std::cin >> i >> val;
            h1.heap_increase_key(i - 1, val);
            h1.printHeap();
            break;

        case 6:
            exit(0);
        }
    }

    return 0;
}