#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;


bool detectCycle(Node* head){
    // if the list is empty, no need to go thorugh algorithm, simply return false
    if(head == NULL) return false;
    // create a map to keep track of the node's that are visited
    map<Node*, bool> visited;
    Node* current = head;
    while(current != NULL){
        if(visited[current] == true){
            // if the current node exist in the visited list we are in a loop
            return true;
        }
        // add each unvisited node in the map
        visited[current] = true;
        // move pointer to next node
        current = current->next;
    }
    // if out of the loop a node with NULL was detected, so it is not a circular linked list
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
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    // manual setup of head of linked list
    Node* head = n1;

    // print(head);
    cout<<detectCycle(head)<<endl;
}