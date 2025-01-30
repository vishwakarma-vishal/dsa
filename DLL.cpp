#include<bits/stdc++.h>
using namespace std; 

struct Node {
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data1, Node* prev1, Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convert2DLL(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* pre = head;
   
    for (int i = 1; i < size; i++) {
        Node* temp = new Node(arr[i], pre, nullptr);
        pre->next = temp;
        pre = temp;
    }

    return head;
}

void printDLL(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* pre = head;

    head = head->next;
    head->prev = nullptr;
    pre->next = nullptr;
    delete pre;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail = head;

    while(tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newTail = tail->prev;
    tail->prev = nullptr;
    newTail->next = nullptr;
    free(tail);

    return head;
}

Node* insertBeforeHead(Node* head, int value) {
    if (head == NULL) {
        return NULL;
    }

    Node* newHead = new Node(value);
    newHead->next = head;
    head->prev = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int value) {
    if (head->next == NULL) {
        return insertBeforeHead(head, value);
    }

    Node* temp = head;

    while(temp->next) {
        temp = temp->next;
    }

    Node* before = temp->prev;

    Node* element = new Node(value);
    before->next = element;
    element->prev = before;

    element->next = temp;
    temp->prev = element;

    return head;
}

Node* insertBeforeKele(Node* head,int position, int value) {
    if (head == NULL) {
        return NULL;
    }
    int pos = 1;
    Node* temp = head;
    while(temp->next) {
        if (pos == position) {
            break;
        }
        temp = temp->next;
        pos++;
    }

    Node* back = temp->prev;

    if (back == NULL) {
        return insertBeforeHead(head, value);
    } else {
        Node* newNode = new Node(value, back, temp);
        back->next = newNode;
        temp->prev = newNode;
    }

    return head;
}

int main () {
    int arr[] = {2, 7 , 9 ,2};
    int size = sizeof(arr) /sizeof(arr[0]);
    
    // convert arr to DLL
    Node* head = convert2DLL(arr, size);
    printDLL(head);    // print DLL
    cout <<endl;

    head = insertBeforeKele(head, 4, 67);
    printDLL(head);
}