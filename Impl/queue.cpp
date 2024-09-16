/* Queue - Circular Array implementation in C++*/
#include<iostream>
using namespace std; 
#define MAX_SIZE 101  //maximum size of the array that will store Queue. 

// Creating a class named Queue.
class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear; 
public:
	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	// To check wheter Queue is empty or not
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(IsFull())
		{
			cout<<"Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void Dequeue()
	{
		cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return A[front];
	}
	/* 
	   Printing the elements in queue from front to rear. 
	   This function is only to test the code. 
	   This is not a standard function for Queue implementation. 
	*/
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};
int main()
{
	/*Driver Code to test the implementation
	  Printing the elements in Queue after each Enqueue or Dequeue 
	*/
   Queue Q; // creating an instance of Queue. 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}

#include <iostream>
#include <stdexcept>

template <typename T>
class CircularQueue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

    void resize(int newCapacity) {
        T* newArr = new T[newCapacity];
        int j = 0;
        for (int i = 0; i < size; i++) {
            newArr[j] = arr[(front + i) % capacity];
            j++;
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    CircularQueue(int cap) : capacity(cap), front(-1), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        int i = front;
        int count = 0;
        while (count < size) {
            std::cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        std::cout << std::endl;
    }
};

#include <iostream>
#include <stdexcept>

template <typename T>
class LinearQueue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    LinearQueue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~LinearQueue() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        rear++;
        arr[rear] = value;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T value = arr[front];
        front++;
        size--;
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return rear == capacity - 1;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void reset() {
        if (front > 0 && rear < capacity - 1) {
            for (int i = 0; i < size; i++) {
                arr[i] = arr[front + i];
            }
            rear = size - 1;
            front = 0;
        }
    }
};