#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string department;
    float cgpa;

    bool operator<(const Student& s2) const {
        return this->cgpa < s2.cgpa;
    }
};

class MaxHeap {
private:    
    std::vector<Student> heap;

    void heapifyUp(int idx);
    void heapifyDown(int idx);
    int parent(int idx) { return (idx - 1) / 2; }
    int leftChild(int idx) { return (idx * 2) + 1; }
    int rightChild(int idx) { return (idx * 2) + 2; }

public:
    void push(Student student);
    Student pop();
};

void MaxHeap::heapifyUp(int idx) {
    if (idx == 0)
        return;

    if (heap[idx] < heap[parent(idx)])
        return;

    std::swap(heap[idx], heap[parent(idx)]);
    heapifyUp(parent(idx));
}

void MaxHeap::heapifyDown(int idx) {
    int size = heap.size();
    int largest = idx;
    int left = leftChild(idx);
    int right = rightChild(idx);

    if (left < size && heap[largest] < heap[left])
        largest = left;

    if (right < size && heap[largest] < heap[right])
        largest = right;

    if (largest != idx) {
        std::swap(heap[idx], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::push(Student student) {
    heap.push_back(student);
    heapifyUp(heap.size() - 1);
}

Student MaxHeap::pop() {
    if (heap.empty())
        throw std::runtime_error("heap empty");

    Student top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return top;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Student> students(N);
    MaxHeap pq;

    for (int i = 0; i < N; i++) {
        std::cin >> students[i].name >> students[i].department >> students[i].cgpa;
        pq.push(students[i]);
    }

    std::vector<Student> sortedStudents;
    for (int i = 0; i < N; i++) {
        sortedStudents.push_back(pq.pop());
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (students[i].cgpa == sortedStudents[j].cgpa) {
                if (j == 0) {
                    std::cout << "Shiny Gold Medal" << std::endl;
                } else if (j == 1) {
                    std::cout << "First to lose" << std::endl;
                } else if (j == 2) {
                    std::cout << "Best among the leftovers" << std::endl;
                } else {
                    std::cout << "Thank you for participating (" << j - 2 << ")" << std::endl;
                }
                break;
            }
        }
    }

    return 0;
}