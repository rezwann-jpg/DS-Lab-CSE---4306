#include <iostream>
#include <cstdlib>
#include <string>

class StackApp {
public:
    StackApp(int n);
    ~StackApp();
    void Run();

private:
    bool isFull();
    bool isEmpty();
    void Push(int x);
    void Pop();
    int Top();
    int Size();
    void PrintStack();

    int *stack;
    int capacity;
    int tos;
};

StackApp::StackApp(int n) {
    stack = (int *)std::malloc(n * sizeof(int));
    capacity = n;
    tos = -1;
}

StackApp::~StackApp() {
    std::free(stack);
}

void StackApp::Run() {
    std::string command;
    
    while (true) {
        std::cin >> command;

        if (command == "/")
            break;

        if (command == "+") {
            int x;
            std::cin >> x;

            Push(x);
        }
        else if (command == "-") {
            Pop();
        }

        PrintStack();
    }
}

bool StackApp::isFull() {
    return tos == capacity - 1;
}

bool StackApp::isEmpty()
{
    return tos == -1;
}

void StackApp::Push(int x) {
    if (isFull()) {
        std::cout << "Overflow !!!" << std::endl;
    }
    else {
        tos++;
        stack[tos] = x;
    }
}

void StackApp::Pop() {
    if (isEmpty()) {
        std::cout << "Underflow !!!" << std::endl;
    }
    else {
        tos--;
    }
}

int StackApp::Top() {
    return isEmpty() ? 0 : stack[tos];
}

int StackApp::Size() {
    return tos + 1;
}

void StackApp::PrintStack() {
    std::cout << "Size : " << Size() << std::endl;
    std::cout << "Stack elements : ";
    for (int i = 0; i < tos + 1; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Top element : " << Top() << std::endl;
    std::cout << "isFull : " << (isFull() ? "True" : "False") << std::endl;
    std::cout << "isEmpty : " << (isEmpty() ? "True" : "False") << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    StackApp st(N);
    st.Run();

    return 0;
}