// . Insertion at the head of linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    // create a new node to add as the new head
    Node* newNode = new Node(d);
    // pointing the next to the head;
    newNode->next = head;
    // assinging new head 
    head = newNode;
}

// printing the linked list
void print(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next; 
    }
    cout<<endl;
}

int main(){
    Node* n1 = new Node(2);
    insertAtHead(n1, 1);
    insertAtHead(n1, 0);
    print(n1);
}