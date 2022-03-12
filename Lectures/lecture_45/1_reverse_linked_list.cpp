#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }

};

// The following solution uses iteration/loop
// time complexity --> O(n)
// space complexity --> O(1)
void reverseLL(Node<int>* &head){
    // if the list is empty or have only one element
    if(head == NULL || head->next == NULL){
        return;
    }
    Node<int>* previous = NULL;
    Node<int>* current = head;

    while(current != NULL){
        Node<int>* forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    head = previous;
}
// The following use recursion
// time complexity --> O(n) n->number of nodes in list
// space complexity --> O(n)
void reverseLL_recursion(Node<int>* previous, Node<int>* current, Node<int>* &head){
    // base case
    if(current == NULL){
        head = previous;
        return;
    }
    Node<int>* forward = current->next;
    reverseLL_recursion(current, forward, head);
    current->next = previous;

}

void print(Node<int>* n){
    while(n != NULL){
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }
    cout<<endl;
}
// time complexity --> O(n) n->number of nodes in list
// space complexity --> O(n)
Node<int>* reverse_LL2(Node<int>* &head){
    //base case
    if(head->next == NULL || head == NULL){
        return head;
    }

    Node<int>* smallHead = reverse_LL2(head->next);
    head->next->next = head;
    head->next = NULL;

    return smallHead;
}
int main(){
    Node<int>* n1 = new Node(1);
    Node<int>* n2 = new Node(2);
    Node<int>* n3 = new Node(3);
    Node<int>* n4 = new Node(4);

    Node<int>* head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node<int>* other = NULL;
    print(head);
    head = reverse_LL2(head);
    print(head);
}