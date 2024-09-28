#include <iostream>
#include <vector>
#include <cstdlib>

class Heap {
public:
    void insert(int key);
    void printHeap();
    int heap_min() {
        return heap[0];
    }
    int heap_extract_min();
    void min_heap_insert(int key);
    void heap_decrease_key(int i, int value);
    void heap_increase_key(int i, int value);
    ///void heapSort();
    void build_min_heap();
private:
    void min_heapify(int i, int n);

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

void Heap::min_heapify(int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = n;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        min_heapify(smallest, n);
    }
}

void Heap::build_min_heap() {
    int N = heap.size();

    int startIdx = (N / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        min_heapify(i, N);
    }
}

///void Heap::heapSort() {
///    build_max_heap();

///    std::cout << "Max Heap: ";
///    printHeap();

///    for (int i = heap.size() - 1; i >= 0; i--) {
///        std::swap(heap[0], heap[i]);

///        max_heapify(0, i);
///    }

///    std::cout << "Sorted: ";
///    printHeap();
///}

int Heap::heap_extract_min() {
    if (heap.size() == 1) {
        return heap[0];
        heap.pop_back();
    }

    int root = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    min_heapify(0, heap.size());

    return root;
}

void Heap::min_heap_insert(int key) {
    heap.push_back(key);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1)/ 2] > heap[i]) {
        std::swap(heap[i], heap[(i - 1)/ 2]);
        i = (i - 1)/ 2;
    }
}

void Heap::heap_decrease_key(int i, int value) {
    heap[i] -= value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        std::swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void Heap::heap_increase_key(int i, int value) {
    heap[i] += value;

    min_heapify(i, heap.size());
}

int main() {
    Heap h1;

    int num;
    while (std::cin >> num) {
        if (num == -1)
            break;

        h1.insert(num);
    }
    /// h1.printHeap();
    ///h1.heapSort();

    h1.build_min_heap();
    std::cout << "Min Heap: ";
    h1.printHeap();

    while (true) {
        int choice, k, i, val;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << h1.heap_min() << std::endl;
            h1.printHeap();
            break;

        case 2:
            std::cout << h1.heap_extract_min() << std::endl;
            h1.printHeap();
            break;

        case 3:
            std::cin >> k;
            h1.min_heap_insert(k);
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
