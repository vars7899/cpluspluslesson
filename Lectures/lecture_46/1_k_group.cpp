#include <bits/stdc++.h>
#include "./LL.cpp"
using namespace std;
// TC --> O(n)
// SC --> O(n/k) --> O(n)
Node<int>* reverse(Node<int>* &head, int K){
    // base case for recursion
    // when the list is empty 
    if(head == NULL ){
        return head;
    }

    Node<int>* next = NULL;
    Node<int>* prev = NULL;
    Node<int>* current = head;
    int count = 0;
    
    while(count < K && current != NULL){
        count++; // increase the counter
        next = current->next; // assinging value to next
        current->next = prev;
        prev = current;
        current = current->next;
    }
    if(next != NULL){
        head->next = reverse(next, K);
    }
    return prev; 
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
    // 1 -> 2 -> 3 -> 4


}
