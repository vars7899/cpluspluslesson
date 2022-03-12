// This solution for cloning a linked list will be better in the sense of space complexity as we will not be creating a map to keep track of the random pointer of the linked list.
// Approach #3 -->
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* rand;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->rand = NULL;
    }
};
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
// function --> to add new Node at the tail of the linked list
void addTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}
bool isClone(Node* LL1, Node* LL2){
    while(LL1 != NULL && LL2 != NULL){
        if(LL1->data != LL2->data) return false;
        if(LL1->rand->data != LL2->rand->data) return false;
        if(LL1->next->data != LL2->next->data) return false;
        // move pointers
        LL1 = LL1->next;
        LL2 = LL2->next;
    }
    return true;
}
Node* cloneLinkedList(Node* head){
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* current = head;
    // Step1: create the clone of the linked list without worrying about the rand property
    while(current != NULL){
        addTail(cloneHead, cloneTail, current->data);
        current = current->next;
    }
    // Step2: add clone linkedlist node in between original linkedlist(important)
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL){
        // for original linked list
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;
        // for clone linked list
        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    } 
    // Step3: add random nodes of original to clone list
    Node* temp = head; 
    while(temp != NULL){
        if(temp->next != NULL){
            temp->next->rand = temp->rand ? temp->rand->next : temp->rand; 
        }
        // move pointer
        temp = temp->next;
        if(temp != NULL) temp = temp->next;
    }
    // Step4: revert changes from step 2
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL){
        // for the original linked list
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        // for the clone linked list
        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
    }
    // Step5: return the clone linked list
    return cloneHead;
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->rand = n3;
    n2->rand = n1;
    n3->rand = n4;
    n4->rand = n2;

    Node* head = n1;
    Node* clone = cloneLinkedList(head);
    cout<<isClone(head, clone)<<endl;
}