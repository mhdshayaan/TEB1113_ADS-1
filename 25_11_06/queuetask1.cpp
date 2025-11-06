#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next_ptr;
};

class Queue {
private:
    Node* front; // (for removing)
    Node* rear;  // (for adding)
    int size;
    int capacity;

public:
    Queue(int cap = 5){
        front = nullptr; 
        rear = nullptr; 
        size = 0;
        capacity = cap;
    }

    bool isEmpty(){
        return front == nullptr; 
    }

    bool isFull(){
        return size >= capacity;
    }

    // 'push' is renamed to 'enqueue' for queues
    void enqueue(string value){
        if (isFull()){
            cout << "Queue is full! Cannot enqueue '" << value << "'." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = nullptr; 

        // Case 1:queue is empty
        if (isEmpty()){
            front = newNode;
            rear = newNode;
        } 
        // Case 2:queue is not empty
        else {
            rear->next_ptr = newNode; // link old rear to the new node
            rear = newNode;           // Update rear pointer
        }
        
        size++;
        cout << "Enqueued: " << value << endl;
    }
    
    // 'pop' is renamed to 'dequeue' for queue
    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front; 
        cout << "Dequeued: " << temp->data << endl;
        
        front = front->next_ptr;
        delete temp;
        size--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void peek() {
        if (isEmpty()){
            cout << "Queue is empty! Nothing to peek." << endl;
        } else{
            cout << "Front element: " << front->data << endl;
        }
    }

    void display() {
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }

        Node * current = front; // displying from the front
        cout << "Queue elements: ";
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next_ptr;
        }

        cout << endl;
    }

    ~Queue() {
        cout << "\nDestroying queue..." << endl;
        while (!isEmpty()) {
            
            dequeue();
        }
    }
};

int main() {
    // Test
    Queue q(3); 

    q.enqueue("Num1");
    q.enqueue("Num2");
    q.enqueue("Num3");
    q.enqueue("Overflow"); 

    q.display(); 

    q.peek(); 
    q.dequeue();
    q.display(); 
    
    q.dequeue(); 
    q.dequeue(); 
    q.dequeue(); 

    return 0;
}

