#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this-> next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    // create a new node that will become the new tail
    Node* newTail = new Node(d);
    // the Tail should point to NULL
    newTail->next = NULL;
    // original tail->next should be pointing to newtail address
    tail->next = newTail;
    tail = newTail;
}
 
void print(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(0);
    Node* tail = new Node(1);
    head->next = tail;
    print(head);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    print(head);
}