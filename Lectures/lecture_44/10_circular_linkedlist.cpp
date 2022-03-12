// . Circular  Linked list --> it is uni-directional linked list in which we can traverse in only one direction, but the last node points to the first node.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void print(Node* n){
    Node* temp = n;
    if(n == NULL) return;
    do{
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }while(n != temp);
    cout<<endl;
}

void insertNode(Node* &tail, int element, int value){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(value); // created new Node with given value
        tail = newNode; // assigned the tail as newly made Node
        newNode->next = newNode; // as it is circular ll pointing to itself
        return;
    }

    Node* current = tail; // pointing to linkedlist head
    while(current->data != element){
        current = current->next;
    }
    Node *newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(Node* &tail, int element){
    // empty list
    if(tail == NULL){
        cout<<"ERROR:--> Empty list"<<endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous->next;

    while(current->data != element){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    cout<<current->data<<" "<<previous->data<<endl;

    // if only one element
    if(current == previous){
        tail = NULL;
    }

    else if(tail == current){
        tail = previous;
    }
    current->next = NULL;
    delete current;
}

// void deleteNode(Node* &tail, int value) {

//     //empty list
//     if(tail == NULL) {
//         cout << " List is empty, please check again" << endl;
//         return;
//     }
//     else{
//         //non-empty

//         //assuming that "value" is present in the Linked List
//         Node* prev = tail;
//         Node* curr = prev -> next;

//         while(curr -> data != value) {
//             prev = curr;
//             curr = curr -> next;
//         }

//         prev -> next = curr -> next;

//         //1 Node Linked List
//         if(curr == prev) {
//             tail = NULL;
//         }

//         //>=2 Node linked list
//         else if(tail == curr ) {
//             tail = prev;
//         }

//         curr -> next = NULL;
//         delete curr;

//     }

// }

int main(){
    
    Node* tail = NULL;

    // Node* n1 = new Node(1);
    // Node* n2 = new Node(2);
    // Node* n3 = new Node(3);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n1;
    // tail = n3;

    insertNode(tail, 0, 1);
    print(tail);
    insertNode(tail, 1, 2);
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    insertNode(tail, 1, 9);
    print(tail);

    deleteNode(tail, 4);
    print(tail);
    cout<<"done"<<endl;
}