// . Deletion of any element in the linked list
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

    // ! important
    // destructor
    ~Node(){
        // free up the memory for head node
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void deleteHead(Node* &head){
    Node* ogHead = head;
    head = head->next;
    ogHead->next = NULL;
    delete ogHead;
}

// ? Deleting the middle node
void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        deleteHead(head);
        return;
    }

    Node* current = head; //position --> 1
    Node* prev = NULL; //position --> 0
    int count = 1;

    while(count<position){
        prev = current;
        current = current->next;
        count++;
    }
    if(current->next == NULL){
        tail = prev;
    }
    prev->next = current->next;
    current->next = NULL;
    delete current;
}


void print(Node* &node){
    Node* n = node;
    while(n != NULL){
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }
    cout<<endl;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    Node* head = n1;
    Node* tail = n4;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    print(head);
    deleteNode(head,tail,4);
    print(head);
}