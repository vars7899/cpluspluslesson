// . Remove duplicates from UNSORTED linked list
// ? there are two wys to do this problem 
// 1. sort the linkedlist and then remove the duplicate elements
// 2. to create a map and keep track if the element already exit in the map, if it is present then we can remove it.
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node<T>* next;
    //constructor
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
    void n(Node* n){
        this->next = n;
    }
};

void print(Node<int>* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

// Time complexity -- O(n)
// space complexity -- O(n)

void RemoveDuplicates(Node<int>* &head){
    //if the list is empty
    if(head == NULL) return;


    map<int, int> visited;

    Node<int>* current = head;
    visited[current->data] = 1;
    Node<int>* prev = current;
    current = current->next;

    while(current != NULL){
        if(visited[current->data]){
            prev->next = current->next;
            delete(current);
        }else{
            visited[current->data] = 1;
            prev = current;
        }
        current = prev->next;
    }
}

int main(){
    Node<int>* n1 = new Node<int>(3);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(2);
    Node<int>* n5 = new Node<int>(3);
    n1->n(n2);
    n2->n(n3);
    n3->n(n4);
    n4->n(n5);
    Node<int>* head = n1;
    print(head);
    RemoveDuplicates(head);
    print(head);
}