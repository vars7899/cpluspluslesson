#include <bits/stdc++.h>
using namespace std;

// This question have different Node structure
class Node{
    public: 
    int data;
    Node* next;
    Node* random;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
void push(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}
// time complexity --> O(n) , where n is the number of nodes in the input linked list
// space complexity --> O(n), where n is the number of nodes in the linked list
Node* clone(Node* head){
    // pointers
    Node* current = head;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    // map
    unordered_map<Node*, Node*> track; 
    while(current != NULL){
        push(cloneHead, cloneTail, current->data);
        track[current] = cloneTail;
        current = current->next;
    }
    current = head;
    Node* cloneNode = cloneHead;
    while(current != NULL){
        cloneNode->random = track[current->random];
        cloneNode = cloneNode->next;
        current = current->next;
    }
    return cloneHead;
}

int main(){

}