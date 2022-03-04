#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

// Find and delete the cycle if it exist in the linked list
// The approach that we are going to use is
// 1. find if it is a cyclic, looped linked list(we are going to use the floyds cyclic detection to find this)
// 2. find the tail of the cyclic linked list and point it to NULL.(floyds cyclic detection to find the tail)

Node* removeLoop(Node* &head){
    if(head == NULL || head->next == NULL) return head;

    // floyds cycle detection algorithm
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL) fast = fast->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(slow == fast){
    // find the tail of the linked list
        Node* tail = NULL;
        slow = head;
        while(slow != fast){
            tail = fast;
            slow = slow->next;
            fast = fast->next;
        }
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return head;
}

void s_print(Node* n){
    if(n == NULL) cout<<"EMPTY list"<<endl;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int main(){
    // creating linked list nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    // Node* n5 = new Node(5);
    // Node* n6 = new Node(6);
    // set up the next prop of each node
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    // n5->next = n6;
    // n6->next = n4;
    // manual setup of head of linked list
    Node* head = NULL;

    // s_print(head); // gives infinite loop as cycle exist
    head = removeLoop(n1);
    // s_print(head);
}