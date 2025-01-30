// deletion of the head
#include<bits/stdc++.h>
using namespace std;

// class Node 
class Node {
    public:
    int data;
    Node* next;

    // constructor
    public:
    Node (int data1, Node* next1) {
        data = data1;                                                                                                                                                                                                               
        next = next1;
    }
    
    // constructor
    public:
    Node (int data1) {
        data = data1;
        next = nullptr;
    }
};

// converting array to linked list
Node* convertArr2ll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// print all element
void printLinkedList(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// insert ele at the tail
void insertEle(Node* head, int position, int ele) {
    Node* temp = head;
    Node* pre;
    Node* newEle = new Node(ele);

    while (temp->next) {
        if (temp->data == position) {
            pre->next = newEle;
            newEle->next = temp;
            break;
        } else{
        pre = temp;
        temp = temp->next;
        }
    }
}

int main() {
    vector<int> arr = {3, 67, 30, 9, 5};

    // creating linked list
    Node* head = convertArr2ll(arr);
    printLinkedList(head);
    cout << endl;
    insertEle(head, 9, 40);
    // insert ele (head, tail, index, ele)
    printLinkedList(head);
}