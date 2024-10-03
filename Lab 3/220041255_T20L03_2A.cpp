#include <iostream>
#include <vector>

class Heap {
public:
    void insert(int key);
    void printHeap();
    void heapSort(int K);
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

void Heap::heapSort(int K) {
    build_min_heap();

    // std::cout << "Max Heap: ";
    // printHeap();

    for (int i = heap.size() - 1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);

        min_heapify(0, i);
    }

    // printHeap();
    std::cout << heap[K - 1] << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    int K;
    std::cin >> K;

    Heap h1;

    for (int start = 0; start < N; start++) {
        int sum = 0;
        for (int end = start; end < N; end++) {
            sum += nums[end];

            h1.insert(sum);
        }
    }

    h1.heapSort(K);

    return 0;
}