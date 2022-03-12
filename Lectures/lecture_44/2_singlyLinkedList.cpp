// . Singly Linked list 
// ? singly Linkedlist that is uni-directional that can only be traversed in one direction from head node to tail.
// ? for example
// ? [10,memAddressOfNextNode] -> [20,memAddressOfNextNode] ->[10,memAddressOfNextNode] -> [10,null]
#include <bits/stdc++.h>
using namespace std;

class Node{
    // NODE will have two properties
    // 1. Data feild
    public:
    double data;
    // 2. pointer to next node
    Node* next;

    // constructor
    Node(double data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    // Head of the linked list
    Node* head = new Node(1);
    // by default the head is pointing to no other node
    Node* second = new Node(2);

    head->next = second;

    // This way we have created a linked list with two elements
    cout<<head->next<<endl;
    cout<<second<<endl;
}