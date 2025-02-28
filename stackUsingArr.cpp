#include <bits/stdc++.h>
using namespace std;

// implementing stack using array
class StackImp {
    int Top;
    int *stack;
    int capacity;

    public:
    //constructor
    StackImp(int size) {
        Top = -1;
        capacity = size;
        stack = new int[size];
    }

    //push
    void push(int ele) {
        if(Top == capacity - 1) cout << "Stack is full.\n";
        else {
            Top++;
        stack[Top] = ele;
        }
    }

    //pop
    void pop(){
        if (Top == - 1) cout << "Stack is empty.\n";
        else {
            cout << stack[Top] << endl;
            Top--;
        }
    }

    //top
    void top(){
        cout << stack[Top] << endl;
    }

    //size
    void size(){
        cout << Top + 1 << endl;
    } 
};

int main (){
    StackImp stack(4);

    stack.push(4);
    stack.push(4);
    stack.push(4);

    return 0;
}