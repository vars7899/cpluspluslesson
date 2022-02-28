// . Inserting element at the starting of a linked list/ assigning a new head to the linked list

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

    Node(Node* prev, Node* next, int data){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
int getLength(Node* head){
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}
// insert at the head
void insertAtHead(Node* &head,Node* &tail, int value){
    // ! empty list case
    if(head == NULL){
        Node* newHead = new Node(value);
        head = newHead;
        tail = newHead;
        return;
    }

    // create a new node for value
    Node* newHead = new Node(value);
    newHead->next = head; // next prop to pointing to head
    head->prev = newHead; // head prev prop pointing to newHead;
    head = newHead; // updating the head
}
// insert at the tail
void insertAtTail(Node* &tail,Node* &head, int value){
    // ! empty list case
    if(tail == NULL){
        Node* newTail = new Node(value);
        tail = newTail;
        head = newTail;
        return;
    }
    //create a new Node for value
    Node* newTail = new Node(value);
    newTail->prev = tail; // newTail prev prop should be pointing to tail
    tail->next = newTail; // tail next prop should be pointing to newTail 
    tail = newTail; //update the tail value
}
// insert in between
void insert(Node* &head, Node* &tail, int position, int value){
    if(position > getLength(head) + 1){
        cout<<"\nError: Cannot add NODE--> "<<value<<"\n"<<endl;
        return;
    } 
    if(position == 1){
        insertAtHead(head, tail, value);
        return;
    }
    Node* temp = head;

    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(tail, head, value);
        return;
    }
    Node* newNode = new Node(value);\
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->prev = newNode; // ! important
}

void deleteNode(Node* &head, int position){
    // To delete the head node
    if(position == 1){
        Node* og = head;
        head = head->next;
        head->prev = NULL;
        og->next = NULL;
        delete og;
    }else{
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while(count < position){
            previous = current;
            current = current->next;
            count++;
        }
        // ! important CODE
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
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
    Node* tail = NULL;
    // Node* n1 = new Node(NULL,NULL,1);
    // Node* n2 = new Node(n1,NULL,2);
    // Node* n3 = new Node(n2,NULL,3);
    // Node* n4 = new Node(n3,NULL,4);

    // head = n1;
    // tail = n4;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;

    insertAtHead(head, tail, 1);
    print(head);

    insertAtTail(tail, head, 5);
    print(head);


    insert(head, tail, 2, -20);
    print(head);

    insert(head, tail, 4, -10);
    print(head);

    deleteNode(head, 4);
    print(head);

    // ! if the linked list is empty the code will give a segmentation fault, we will fix it by changing the code if head is NULL
}