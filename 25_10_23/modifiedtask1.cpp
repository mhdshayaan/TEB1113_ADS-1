#include <iostream>
using namespace std;

struct Node{
    string data;
    Node* next_ptr;
};

class Stack {
private:
    Node* top;
    int size;
    int capacity;

public:
    Stack(int cap = 5){
        top = nullptr;
        size = 0;
        capacity = cap;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    bool isFull(){
        return size >= capacity;
    }

    void push(string value){
        if (isFull()){
            cout << "Stack is full! Cannot push '" << value << "'." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = top;
        top = newNode;
        size++;

        cout << "Pushed: " << value << endl;


    }
    
    void pop(){
        if (isEmpty()){
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next_ptr;
        delete temp;
        size--;
    }

    void peek() {
        if (isEmpty()){
            cout << "Stack is empty! Nothing to peek." << endl;
        } else{
            cout << "Top element: " << top->data << endl;
        }
    }

    void display() {
        if (isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }

        Node * current = top;
        cout << "Stack elements: ";
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next_ptr;
        }

        cout << endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s(3);

    s.push("Num1");
    s.push("Num2");
    s.push("Num3");
    s.push("Overflow");

    s.display();

    s.peek();
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
