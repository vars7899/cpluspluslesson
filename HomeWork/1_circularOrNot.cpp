#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

// find if a list is circular or not
bool isCircular(Node* head){
    // if the list is empty
    // if(head == NULL) return false;

    Node* temp = head;

    do{
        if(temp == NULL){
            return false;
        }
        temp = temp->next;
    }while(temp != head);

    return true;
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
    n6->next = n1;
    // manual setup of head of linked list
    Node* head = n1;

    print(head);
    cout<<isCircular(NULL)<<endl;
}