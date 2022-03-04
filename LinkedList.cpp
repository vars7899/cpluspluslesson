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