#include <bits/stdc++.h>
using namespace std;

// Class for each node of the Linked List
class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// print function for linked list with loop
void print(Node* head){
    Node* temp = head;
    // if the list is empty
    if(temp == NULL) return; 
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

void print2(Node* head){
    Node* temp = head;
    // if the list is empty
    if(temp == NULL) return; 
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}