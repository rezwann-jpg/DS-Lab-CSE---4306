#include <iostream>
#include <vector>

class Heap {
public:
    void insert(int key);
    void printHeap();
    void heapSort();
private:
    void min_heapify(int i, int n);
    void build_min_heap();

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

void Heap::heapSort() {
    build_min_heap();

    std::cout << "Max Heap: ";
    printHeap();

    for (int i = heap.size() - 1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);

        min_heapify(0, i);
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
    h1.heapSort();

    return 0;
}