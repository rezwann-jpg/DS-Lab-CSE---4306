#include <iostream>
#include <vector>

class Heap {
public:
    void insert(int key);
    void printHeap();
    void heapSort();
private:
    void max_heapify(int i, int n);
    void build_max_heap();

    std::vector<int> heap;
};

void Heap::insert(int key) {
    heap.push_back(key);
    ///int i = heap.size() - 1;

    ///while (i != 0 && heap[(i - 1)/ 2] < heap[i]) {
    ///    std::swap(heap[i], heap[(i - 1)/ 2]);
    ///    i = (i - 1)/ 2;
    ///}
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

void Heap::heapSort() {
    build_max_heap();

    std::cout << "Max Heap: ";
    printHeap();

    for (int i = heap.size() - 1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);

        max_heapify(0, i);
    }

    std::cout << "Sorted: ";
    printHeap();
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
    h1.heapSort();

    return 0;
}
