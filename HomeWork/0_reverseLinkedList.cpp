#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

//. 1. To reverse a Linked list using iteration
// We use three pointer in this approach
// 1) previous, initiating from NULL as the first element would be the last element and the tail of linked list always point to NULL.
// 2) current, initiating at the head of the linked list.
// 3) next, initiating from NULL, pointer to not lose track of the linked list.

// Time complexity --> O(n), where n is the number of nodes in the linked list, this is O(n) as we are traversing through all the nodes in the linked list.
// space complexity --> O(1), constant time as we only making some pointers and nothing else.
Node* reverseLink(Node* &head){
    // base case
    // for empty list and list with one element
    if(head == NULL || head->next == NULL) return head;

    // pointers
    Node* previous = NULL;
    Node* current = head;
    Node* next = NULL;

    // traverse though the list
    while(current != NULL){
        next = current->next;
        current->next = previous;
        // move to next node in list
        previous = current;
        current = next;
    }
    return previous;
}
//. 2. Reverse the linked list using recursion
Node* reverseRecursion(Node* head){
    // base case
    // when we reach the end of the list or the list is empty
    // if there is linked list with only one node.
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* smallHead = reverseRecursion(head->next);
    cout<<smallHead->data<<endl;
    head->next->next = smallHead->next;
    head->next = NULL;

    return smallHead;
}

int main(){
    // creating linked list nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    // set up the next prop of each node
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    // manual setup of head of linked list
    Node* head = n1;

    print2(head);
    print2(reverseRecursion(head));
}