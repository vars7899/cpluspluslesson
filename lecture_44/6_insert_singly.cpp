// . Insert anywhere in the linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;

    // constructor
    Node(string data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, string d){
    // create a new node for element to be added
    Node* newHead = new Node(d);
    newHead->next = head;
    head = newHead;
}

void insertAtTail(Node* &tail, string d){
    // create a new node for element to be added as new tail
    Node* newTail = new Node(d);
    tail->next = newTail;
    tail = newTail;
}

void insert(Node* &head, Node* &tail, int position, string value){
    if(position == 1){
        insertAtHead(head, value);
        return;
    }

    // traverse throught the linkedlist
    Node* current = head;
    int count = 1;

    while(count < position - 1){
        current = current->next;
        count++;
    }

    if(current->next == NULL){
        insertAtTail(tail, value);
        return;
    }

    // create a new Node to add the element with given value
    Node* newNode = new Node(value);
    newNode->next = current->next; 
    current->next = newNode;
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

    Node* n1 = new Node("og_head");
    
    Node* head = n1;
    Node* tail = n1;

    print(head);

    insert(head, tail, 1, "new_head");
    print(head);

    insertAtTail(tail, "og_tail");
    print(head);

    insert(head, tail, 4, "new_tail");
    print(head);
}