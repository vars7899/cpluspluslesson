// . Insertion of new Node anywhere in the middle of a linked list
#include <bits/stdc++.h>
using namespace std;

// create Node class
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// The below code will not work properly for position 1 and last position
void insertAtMiddle(Node* &head, int position, int d){

    Node* start = head;
    int count = 1;

    // traversing through the linkedlist
    while(count < position - 1){
        start = start->next;
        count++;
    }

    // create a new Node
    Node* newNode = new Node(d);

    // put the newNode next as old start next
    newNode->next = start->next;
    // put the new node address as the new next of start
    start->next = newNode;
}

void print(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    print(head);
    // we want to add an element between node second and node third;
    insertAtMiddle(head, 2, 10);
    print(head);
}