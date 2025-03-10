// CMPS 385_Assignment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

class QueueException : public runtime_error {
public:
    explicit QueueException(const string& message) : runtime_error(message) {}
};

template <class T>
class QueueNode {
public:
    T item;
    QueueNode<T>* next;

    QueueNode(const T& newItem) : item(newItem), next(nullptr) {}
};

template <class T>
class Queue {
public:
    Queue(); 
    Queue(const Queue& rhs); 
    ~Queue(); 

    Queue& operator=(const Queue& rhs); 

    bool isEmpty() const; 

    void enqueue(const T& newItem); 

    void dequeue(); 

    void dequeue(T& queueFront); 

    void getFront(T& queueFront) const; 

    void display() const;

private:
    QueueNode<T>* backPtr;
    QueueNode<T>* frontPtr;

    void copyQueue(const Queue& rhs); // Helper to copy queue
};

template <class T>
Queue<T>::Queue() : backPtr(nullptr), frontPtr(nullptr) {}

// Destructor
template <class T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Copy constructor
template <class T>
Queue<T>::Queue(const Queue& rhs) : backPtr(nullptr), frontPtr(nullptr) {
    copyQueue(rhs);
}

// Assignment operator
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& rhs) {
    if (this != &rhs) {
        while (!isEmpty()) {
            dequeue();
        }
        copyQueue(rhs);
    }
    return *this;
}

//  copy queue
template <class T>
void Queue<T>::copyQueue(const Queue& rhs) {
    if (rhs.isEmpty()) return;

    QueueNode<T>* current = rhs.frontPtr;
    while (current) {
        enqueue(current->item);
        if (current == rhs.backPtr) break;
        current = current->next;
    }
}

// isEmpty function
template <class T>
bool Queue<T>::isEmpty() const {
    return backPtr == nullptr;
}

// enqueue fnction
template <class T>
void Queue<T>::enqueue(const T& newItem) {
    QueueNode<T>* newPtr = new QueueNode<T>(newItem);

    if (isEmpty()) {
        frontPtr = newPtr;
    }
    else {
        backPtr->next = newPtr;
    }
    backPtr = newPtr;
}

// dequeue function 
template <class T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        throw QueueException("QueueException: empty queue, cannot dequeue");
    }

    QueueNode<T>* tempPtr = frontPtr;

    if (frontPtr == backPtr) {
        frontPtr = nullptr;
        backPtr = nullptr;
    }
    else {
        frontPtr = frontPtr->next;
    }

    delete tempPtr;
}

// dequeue function 
template <class T>
void Queue<T>::dequeue(T& queueFront) {
    if (isEmpty()) {
        throw QueueException("QueueException: empty queue, cannot dequeue");
    }

    queueFront = frontPtr->item;
    dequeue();
}

// getFront function
template <class T>
void Queue<T>::getFront(T& queueFront) const {
    if (isEmpty()) {
        throw QueueException("QueueException: empty queue, cannot getFront");
    }

    queueFront = frontPtr->item;
}

// display function
template <class T>
void Queue<T>::display() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    QueueNode<T>* current = frontPtr;
    while (current) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    try {
        Queue<int> q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.display(); 

        int front;
        q.getFront(front);
        cout << "Front element: " << front << endl; 

        q.dequeue();
        q.display(); 

        q.dequeue(front);
        cout << "Dequeued: " << front << endl; 

        q.display(); 

    }
    catch (const QueueException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
