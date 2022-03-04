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

// . Sort a given linked list and sort them in 0, 1, 2.
// . for example,
// . I/P --> {1 2 2 1 0 0 2 1}
// . O/P --> {0 0 1 1 1 2 2 2}
// ? The following are the approaches used to solve this problem.
// ? 1. if the output does not want the change the already existing linked list, then we can simply count the number of 0, 1 and 2 in the linked list and then create a linked list counted number of 0,1 and 2.
// ? 2. When data replacement is not allowed,


Node* sort_1(Node* head){
    // create MAP to keep track of number of 0,1 and 2
    map<int, int> table;
    Node* current = head;
    while(current != NULL){
        if(table[current->data]){
            table[current->data]++;
        }else{
            table[current->data] = 1;
        }
        current = current->next;
    }
    // create a linked list
    current = head;
    while(current != NULL){
        if(table[0] != 0){
            current->data = 0;
            table[0]--;
        }else if(table[1] != 0){
            current->data = 1;
            table[1]--;
        }else if(table[2] != 0){
            current->data = 2;
            table[2]--;
        }
        current = current->next;
    }
    return head;
} 
// space complexity --> O(n), where n is the number of node, as we are traversing through each node in the linked list
// time complexity --> O(1)
Node* sort_2(Node* &head){
    // if the list is empty or the list only has one element 
    if(head == NULL || head->next == NULL) return head;
    // create linked list for each 0 1 and 2
    Node* zeroLL = new Node(0);
    Node* oneLL = new Node(0);
    Node* twoLL = new Node(0);
    // pointer for I/P linked list
    Node* current = head;
    // pointer for each 0,1,2 linked list
    Node* zero = zeroLL, *one = oneLL, *two = twoLL;
    while(current != NULL){
        if(current->data == 0){
            zero->next = current;
            zero = zero->next;
        }else if(current->data == 1){
            one->next = current;
            one = one->next;
        }else if(current->data == 2){
            two->next = current;
            two = two->next;
        }
        current = current->next;
    }

    zero->next = ((oneLL->next) ? (oneLL->next) : (twoLL->next));
    one->next = twoLL->next;
    two->next = NULL;
    head = zeroLL->next;

    // free up the heap memory
    free(zeroLL);
    free(oneLL);
    free(twoLL);


    return head;
}

int main(){
    Node* n1 = new Node(2);
    Node* n2 = new Node(1);
    Node* n3 = new Node(2);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);
    n1->n(n2);
    n2->n(n3);
    n3->n(n4);
    n4->n(n5);
    Node* head = n1;
    print(head);
    // Node* c = sort_1(head);
    Node* c = sort_2(head);
    print(c);
}