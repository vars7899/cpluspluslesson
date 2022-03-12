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

void print(Node<int>* n){
    while(n != NULL){
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }
    cout<<endl;
}

// Approach 1
// T.C --> O(n) , where n is the number of nodes in the linked list
Node<int>* getMid(Node<int>* &head){
    Node<int>* n = head;
    Node<int>* res = head;
    int length = 0;
    int mid = 0;
    while(n != NULL){
        length++;
        n = n->next;
    }

    mid = (length/2);
    
    int i = 0;
    while(i < mid){
        res = res->next;
        i++;
    }
    
     return res;
}

// better approach
// T.C --> O(n/2) --> O(n) , where n is the number of nodes
// S.C --> O(1)
Node<int>* getMiddle(Node<int>* &head){

    // base case's
    // if empty list or
    // if only one element in list
    if(head->next == NULL || head == NULL) return head;
    // if two element
    if(head->next->next == NULL) return head->next;

    Node<int>* slow = head;
    Node<int>* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        // check for even number
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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

    print(head);
    Node<int>* middle = getMiddle(head);
    cout<<middle->data<<endl;
}