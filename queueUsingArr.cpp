#include<bits/stdc++.h>
using namespace std;

class QueueImp{
    int start;
    int end;
    int *queue;
    int capacity;
    int current;

    public:
    QueueImp(int n){
        start = -1;
        end = -1;
        queue = new int[n];
        capacity = n;
        current = 0;
    }

    //push
    void push(int ele){
        if(current == capacity) {
            cout << "Queue is full.\n";
        } else {
            if(start == -1) start = 0;
            end++;
            queue[end] = ele;
            current++;
        }
    }

    //top
    void top(){
        if(start == -1 || current == 0) {
            cout << "Queue is empty.\n";
        } else {
            cout << queue[start] << endl;
        }
    }

    //size
    void size(){
        cout << current << endl;
    }

    //pop
    void pop(){
        if(start == -1 || current == 0) {
            cout << "Queue is empty.\n";
        } else {
            start++;
            current--;
            if(start > end){
                start = -1;
                end = -1;
            }
        }
    }
};

int main (){

    QueueImp queue(5);

    queue.push(4);
    queue.push(3);

    queue.pop();
    queue.pop();

    queue.push(56);
    queue.push(34);
    queue.push(3);

    queue.push(56);
    queue.push(34);
    queue.pop();
    queue.push(3);


 
    cout << "size" <<endl;
    queue.size();
    return 0;
}