#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

// To detect the head of the looped linked list we can use the following to approaches
// 1. To create a map and the first element that is revisited will be the head of the looped linked list. but (TC-->O(n), SC-->O(n), where n is the number of nodes in the linked list).
// 2. better approach is to use the floyds cycle detection algorithm.

Node* getHead(Node* head){
    // if list is empty or has only one non self cyclic element
    if(head == NULL || head->next == NULL) return head;

    // floyds cycle detection algorithm
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL) fast = fast->next;
        slow = slow->next;
        if(slow == fast){
            break;  // point of intersection
        }
    }
    // when the intersection point is found
    // put the slow at the head and move both fast and slow by one step per iteration
    if(slow == fast){
        slow = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    return NULL; // cycle doesnot exist
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
    n6->next = n4;
    // manual setup of head of linked list
    Node* head = n1;

    // print(head);
    cout<<getHead(NULL)->data<<endl;
}