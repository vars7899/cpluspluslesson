#include <bits/stdc++.h>
using namespace std;

// Implementation of Linked list
class LinkedListNode{
    public:
    // Singly linked list has two values
    // 1. data feild (this linkedlist store int type of data)
    int data;
    // 2. pointer to the next node
    LinkedListNode *next;

    // default constructor
    LinkedListNode(){

    }
    // Constructor
    LinkedListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    // Creating a linked list with three elements
    LinkedListNode *head = new LinkedListNode(); 
    LinkedListNode *second = new LinkedListNode(); 
    LinkedListNode *third = new LinkedListNode();

    // accessing data feild of nodes
    head->data = 10; 
    head->next = second; // pointer to next ele

    second->data = 20;
    second->next = third; // pointer to next ele

    third->data = 30;
    third->next = NULL; // last ele pointing to NULL

    cout<<head->data<<endl;
}