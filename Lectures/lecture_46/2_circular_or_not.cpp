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
    Node* n = head;
    if(head == NULL) return;
    do{
        cout<<n->data<<" ";
        n = n->next;
    }while(n != NULL);
    cout<<endl;
}
// TC --> O(n), where n is the number of nodes in the linked list
// SC --> O(1), constant space
bool isCircular(Node* head){
    // for empty list
    if(head == NULL) return true;
    // for element >= 1
    Node* current = head->next;
    while(current != head && current != NULL){
        current = current->next;
    }
    if(current == head) return true;
    return false;
}

// ! important
// check if the given linked list is circular in nature, so it can be both circular linked list, or the tail of the linked list is pointing to some other node and there is some part of the linkedlist that is circular
int getLength(Node* head){
    if(head == NULL) return 0;
    int count = 0;
    Node* checkHead = head;
    while(head != NULL && head != checkHead){
        count++;
        head = head->next;
    }
    return count;
}
// TODO use the map approach to find if circular exist
bool circular(Node* head){
    // for empty
    if(head == NULL) return true;

    int length = getLength(head);
    vector<int> *map = new vector<int>[length];
    int count = 0;
    Node* current = head;
    while(count < length){
        map->push_back(current->data);
        current = current->next;
    }

}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    Node* head = NULL;
    print(head);
    bool flag = isCircular(head);
    flag?cout<<"True"<<endl:cout<<"false"<<endl;
}