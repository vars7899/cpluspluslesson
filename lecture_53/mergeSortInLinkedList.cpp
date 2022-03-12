// . Merge sort in Linked list (important)
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
};
void print(Node* head){
    //base case
    if(head == NULL){ 
        cout<<" NULL"<<endl;
        return;
    }
    cout<<" "<<head->data<<" ->";
    print(head->next);
}
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow pointer will be at the mid of the linked list
    return slow;
}
Node* merge(Node* left, Node* right){
    if(left == NULL) return right; // if the left part is NULL
    if(right == NULL) return left; // if the right part is NULL

    Node* ans = new Node(INT_MIN);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node* mergeSort(Node* head){
    // base case
    if(head == NULL || head->next == NULL) return head;
    // we need to get the mid of the linked list
    Node* mid = getMid(head);
    // Break the linked list into two halves

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL; //to break in two halves
    // sort using recursion
    left = mergeSort(left);
    right = mergeSort(right);
    // merge the linked list
    Node* result = merge(left, right);

    return result;
}
int main(){
    Node* n1 = new Node(5);
    Node* n2 = new Node(4);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Node* head = n1;
    print(head);
    head = mergeSort(head);
    print(head);
}