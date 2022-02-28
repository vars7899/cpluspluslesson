// . Doubly Linked list --> It is a bi-directional linked list in which we traverse in both direction head to tail and tail to head
#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(Node* p , Node* n , int d){
        this->data = d;
        this->next = n;
        this->prev = p;
    }
};

int getLength(Node* ll){
    int count = 0;
    while(ll != NULL){
        ll = ll->next;
        count++;
    }
    return count;
}

void print(Node* n){
    while(n != NULL){
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;

    // Node* n1 = new Node(1);
    // Node* n2 = new Node(2);
    // Node* n3 = new Node(3);
    // Node* n4 = new Node(4);
    
    // head = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;

    // n2->prev = n1;
    // n3->prev = n2;
    // n4->prev = n3;

    Node* n1 = new Node(NULL,NULL,1);
    Node* n2 = new Node(n1,NULL,2);
    Node* n3 = new Node(n2,NULL,3);
    Node* n4 = new Node(n3,NULL,4);

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    print(head);
    cout<<getLength(head);
}
