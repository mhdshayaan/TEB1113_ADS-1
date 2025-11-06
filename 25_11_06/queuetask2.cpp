#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
    Node* prev_ptr;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    Queue(int cap = 5) {
        front = rear = nullptr;
        size = 0;
        capacity = cap;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool isFull() {
        return size >= capacity;
    }

    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue '" << value << "'." << endl;
            return;
        }

        Node* newNode = new Node{value, nullptr, nullptr};

        if (rear == nullptr) { // empty queue
            front = rear = newNode;
        } else {
            rear->next_ptr = newNode;
            newNode->prev_ptr = rear;
            rear = newNode;
        }

        size++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next_ptr;

        if (front != nullptr)
            front->prev_ptr = nullptr;
        else
            rear = nullptr; // queue becomes empty

        delete temp;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    void displayForward() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue (front → rear): ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }

    void displayBackward() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue (rear → front): ";
        Node* current = rear;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev_ptr;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty())
            dequeue();
    }
};

int main() {
    Queue q(3);
    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");
    q.enqueue("Overflow");

    q.displayForward();
    q.peek();
    q.dequeue();
    q.displayForward();
    q.displayBackward();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
