#include <bits/stdc++.h>
using namespace std;

// . Remove duplicates from Sorted linked list

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    public:
    void setNext(Node* &second){
        this->next = second;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* removeDuplicates(Node* head){
    // if the list is empty
    if(head == NULL) return NULL;
    Node* current = head;
    while(current != NULL){
        if(current->next != NULL && current->data == current->next->data){
            Node* NodeToDelete = current->next;
            current->next = current->next->next;
            delete NodeToDelete;
        }else{
            current = current->next;
        }
    }
    return head;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(1);
    Node* n3 = new Node(1);
    Node* n4 = new Node(1);
    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(n4);
    Node* head = n1;
    // print(head);
    Node* rm  = removeDuplicates(head);
    print(rm);
}