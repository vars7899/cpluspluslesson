// . Spilt a circular linked list into two half
// if the given linked list has even number of nodes, the output will be two linked list with each length n/2.
// I/P - {1 2 3 4 5 6} 
// O/P - {1 2 3} {4 5 6}
// if the given linked list has odd number of node, the output will be two linkled list one with n/2 length and other with n/2 - 1 length
// I/P - {1 2 3 4 5} 
// O/P - {1 2 3} {4 5}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = next;
    }
    void n(Node* n){
        this->next = n;
    }
};

void print(Node* n){
    Node* temp = n;
    if(n == NULL){
        return;
    }
    do{
        cout<<n->data<<" ";
        n = n->next;
    }while(n != temp);
    cout<<endl;
}

pair<Node*, Node*> split(Node* &head){
    pair<Node*, Node*> ans = {NULL, NULL};
    //if LL with no elements
    if(head == NULL){
        return ans;
    }
    //if array with only one element
    if(head == head->next){
        ans.first = head;
        return ans;
    }
    //get the length of the linked list
    double length = 0;
    Node* temp = head;
    do{
        length++;
        temp = temp->next;
    }while(temp != head);
    // for the first circular linked list
    Node* head_1 = head;
    Node* tail = head;
    Node* head_2 = head;
    Node* prev = NULL;

    cout<<ceil(length/2)<<endl;
    int count = 0;
    while(count < ceil(length/2)){
        count++;
        prev = tail;
        head_2 = tail->next;
        tail = tail->next;
    }

    prev->next = head_1;

    while(tail->next != temp){
        tail = tail->next;
    }
    tail->next = head_2;

    //storing data
    ans.first = head_1;
    ans.second = head_2;

    return ans;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->n(n2);
    n2->n(n3);
    n3->n(n4);
    n4->n(n1);
    // n5->n(n1);
    Node* head = n1;
    print(head);
    pair<Node*, Node*> newLL = split(head);
    print(newLL.first);
    print(newLL.second);
}