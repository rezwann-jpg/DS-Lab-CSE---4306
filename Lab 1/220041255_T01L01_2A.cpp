#include <iostream>
#include <cstdlib>

class StackApp {
public:
    StackApp(int n);
    ~StackApp();
    void Menu();

private:
    void Push(int x);
    void Pop();
    bool isEmpty();
    bool isFull();
    int Size();
    int Top();
    void PrintStack();

    int *stack;
    int sizeOfStack;
    int tos;
};

StackApp::StackApp(int n) {
    sizeOfStack = n;
    tos = -1;
    stack = (int *)malloc(sizeOfStack * sizeof(int));
}

StackApp::~StackApp() {
    free(stack);
}

void StackApp::Menu() {
    int choice;
    int x;

    while (true) {
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cin >> x;
            Push(x);
            PrintStack();
            break;

        case 2:
            Pop();
            PrintStack();
            break;

        case 3:
            if (isEmpty()) 
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
            break;

        case 4:
            if (isFull()) 
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
            break;

        case 5:
            std::cout << Size() << std::endl;
            break;

        case 6:
            std::cout << Top() << std::endl;
            break;

        case -1:
            exit(EXIT_SUCCESS);
        
        default:
            break;
        }
    }
}

void StackApp::Push(int x) {
    if (isFull()) {
        std::cout << "Overflow" << std::endl;
        return;
    }

    tos++;
    stack[tos] = x;
}

void StackApp::Pop() {
    if (isEmpty()) {
        std::cout << "Underflow" << std::endl;
        return;
    }

    tos--;
}

bool StackApp::isEmpty()
{
    return tos == -1;;
}

bool StackApp::isFull()
{
    return tos == sizeOfStack - 1;
}

int StackApp::Size()
{
    return tos + 1;
}

int StackApp::Top()
{
    return stack[tos];
}

void StackApp::PrintStack() {
    for (int i = 0; i < tos + 1; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    int N;
    std::cin >> N;

    StackApp stk(N);
    stk.Menu();

    return 0;
}