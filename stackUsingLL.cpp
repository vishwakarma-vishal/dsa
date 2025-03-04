#include<bits/stdc++.h>
using namespace std;

// stack implementation using linked list

struct Node {
    int data;
    Node* next;

    Node(int x) { // Added constructor for Node
        data = x;
        next = nullptr;
    }
};

class Stack {
    Node* top;
    int size;

public:
    Stack() { // Corrected the constructor definition
        top = nullptr;
        size = 0;
    }

    ~Stack() { // Destructor to free memory
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x) {
       Node* ele = new Node(x);
        ele->next = top;
        top = ele;
       size++;
    }

    void pop() {
       if(top == nullptr) {
        cout << "Stack is empty\n";
       } else {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
       }
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is " << s.peek() << endl;
    s.pop();
    s.pop();
    cout << "Top element is " << s.peek() << endl;
    cout << "Stack size is " << s.getSize() << endl;
    return 0;
}