// . Approach
// The doubly linked list is already a bidirectional linked list, so we just need to change the head of the linked list with the tail of the linked list and interchange the next prop with the previous prop

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node<T>* next;
    Node<T>* previous;

    Node(T data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

void print(Node<int>* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void reverse(Node<int>* &head){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node<int>* temp = NULL;
    Node<int>* current = head;
    while(current != NULL){
        // interchange the value of previous prop and next prop of each node.
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;

        current = current->previous;
    }
    head = temp->previous;
}

int main(){
    Node<int>* n1 = new Node(1);
    Node<int>* n2 = new Node(2);
    Node<int>* n3 = new Node(3);
    Node<int>* n4 = new Node(4);
    Node<int>* n5 = new Node(5);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->previous = n4;
    n4->previous = n3;
    n3->previous = n2;
    n2->previous = n1;

    Node<int>* head = n1;
    // cout<<head->data<<endl;
    reverse(head);
    print(head);
}