#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_ptr;
    Node* prev_ptr;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

   
    bool isEmpty() {
        return head == nullptr;
    }

   
    void push_front(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev_ptr = nullptr;
        newNode->next_ptr = head;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            head->prev_ptr = newNode;
            head = newNode;
        }
        cout << "Pushed front: " << value << endl;
    }

  
    void push_back(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = nullptr;
        newNode->prev_ptr = tail;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next_ptr = newNode;
            tail = newNode;
        }
        cout << "Pushed back: " << value << endl;
    }

   
    void pop_front() {
        if (isEmpty()) {
            cout << "List is empty! Cannot pop front." << endl;
            return;
        }
        Node* temp = head;
        cout << "Popped front: " << temp->data << endl;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next_ptr;
            head->prev_ptr = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "List is empty! Cannot pop back." << endl;
            return;
        }
        Node* temp = tail;
        cout << "Popped back: " << temp->data << endl;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev_ptr;
            tail->next_ptr = nullptr;
        }
        delete temp;
    }


    void display_forward() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Forward traversal: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }


    void display_backward() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Backward traversal: ";
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev_ptr;
        }
        cout << endl;
    }


    ~DoublyLinkedList() {
        while (!isEmpty()) {
            pop_front();
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push_back("test1");
    dll.push_back("test2");
    dll.push_back("test3");
    dll.display_forward();
    dll.display_backward();

    dll.push_front("start");
    dll.display_forward();

    dll.pop_front();
    dll.pop_back();
    dll.display_forward();

    return 0;
}
