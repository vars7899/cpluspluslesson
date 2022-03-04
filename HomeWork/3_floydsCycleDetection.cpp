#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

bool cycleDetect(Node* head){
    //if the list is empty
    if(head == NULL) return false;
    // we will use the Floyds cycle detection here
    // In this algorithm, we take two pointers(slow and fast) one that moves up by one step in the link each iteration and other that move by two step up in the link each iteration. both the pointers will have the same starting node
    // if there is no loop in the linked list the fast would never meet slow again, as it is moving double the speed of the first one but if they meet again it clearly means that a loop exist in the linked list
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        //move fast by two
        fast = fast->next;
        if(fast != NULL) fast = fast->next;
        //move slow by one
        slow = slow->next;
        // check
        if(slow == fast) return true;
    }
    
    return false;

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
    n1->next = n1;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n4;
    // manual setup of head of linked list
    Node* head = n1;

    // print(head);
    cout<<cycleDetect(head)<<endl;
}
