// Given there are two linked list each of the given linked list is sorted, we want to return a linked list that contains the elements of the both linked list.
// I/P -- {1,2,3,4} {5,6,7}
// O/P -- {1,2,3,4,5,6,7}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    void n(Node* n){
        this->next = n;
    }
};

void print(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}
// time complexity -- O(n)
// space complexity -- O(1)
void solve(Node* &first, Node* &second){
    // if only one element is present in the first list
    if(first->next == NULL){
        first->next = second;
        return;
    }
    Node* current_1 = first;
    Node* next_1 = first->next;
    Node* current_2 = second;
    Node* temp = NULL;
    // next_1 should not be NULL and current_2 should not NULL too
    while(next_1 && current_2){ 
        if(current_2->data >= current_1->data && current_2->data <= next_1->data){
            current_1->next = current_2;
            temp = current_2->next;
            current_2->next = next_1;
            current_2 = temp;
            current_1 = current_1->next;
        }else{
            current_1 = next_1;
            next_1 = next_1->next;
            // if the first list is ended, put the current_1->next to the rest of the current_2
            if(next_1 == NULL){
                current_1->next = current_2;
                return;
            }
        }
    }
}

Node* mergeLL(Node* head_1, Node* head_2){
    // if the first list is empty
    if(head_1 == NULL) return head_2;
    // if second list is empty
    if(head_2 == NULL) return head_1;

    if(head_1->data < head_2->data){
        solve(head_1,head_2);
        return head_1;
    }else{
        solve(head_2,head_1);
        return head_2;
    }
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(8);
    Node* n5 = new Node(9);
    n1->n(n2);
    n2->n(n3);
    n3->n(n4);
    n4->n(n5);
    Node* head_1 = n5;
    Node* l1 = new Node(2);
    Node* l2 = new Node(7);
    Node* l3 = new Node(11);
    Node* l4 = new Node(17);
    Node* l5 = new Node(18);
    l1->n(l2);
    l2->n(l3);
    l3->n(l4);
    l4->n(l5);
    Node* head_2 = l1;
    print(head_1);
    print(head_2);
    Node* NL = mergeLL(head_1, head_2);
    print(NL);
}