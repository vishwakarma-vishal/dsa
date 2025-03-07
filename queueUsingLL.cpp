#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class QueueImp {
    Node* front;
    Node* rear;
    int size;

    public:
    QueueImp(){
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    //push
    void push(int x){
        Node* ele = new Node(x);
        if (rear != nullptr) {
            rear->next = ele;
        }

        rear = ele;
        if(front == nullptr) {
            front = ele;
        }
        size++;
    }

    //pop
    int pop(){
        if(rear == nullptr) {
            cout << "queue is empty\n";
            return -1;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr) {
            rear = nullptr;
        }
        int data = temp->data;
        delete temp;
        size--;
        return data;
    }

    //top
    int top() {
        if(front == nullptr) {
            cout << "queue is empty\n";
            return -1;
        }
        return front->data;
    }

    //size
    int getSize(){
        return size;
    }

    //isEmpty
    bool isEmpty(){
        return size == 0;
    }

};

int main(){
    QueueImp q;

    q.push(51);
    q.push(89);
    q.push(5);

    q.pop();

    cout << q.top();
}