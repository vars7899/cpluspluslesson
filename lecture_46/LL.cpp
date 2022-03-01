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
    };
};

void print(Node<int>* n){
    while(n != NULL){
        cout<<n->data;
        n->next == NULL ? cout<<"" : cout<<" -> ";
        n = n->next;
    }
    cout<<endl;
}