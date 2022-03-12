#include <bits/stdc++.h>
using namespace std;

// ? Implementation of the stack using arrays/vectors
class Stack{
    // Data members of Stack class
    public:
    int* arr; // size of the array
    int top; // position to add the new element
    int size = 0;
    Stack(int size){
        this->size = size;
        // create new array with user defined size in heap
        arr = new int[this->size];
        top = -1;
    }
    // Functional members of Stack class
    // push --> insert element at the back
    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        }else{
            cout<<"Stack overflowed"<<endl;
            return;
        }
        
    }
    // pop --> remove element from the back
    void pop(){
        if(top < 0){
            cout<<"Stack underflowed"<<endl;
            return;
        }
        top--;
    }
    // peek --> return last element of the stack
    int peek(){
        if(top < 0){
            cout<<"No elements in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    // empty --> to check if the stack is empty or not
    bool empty(){
        if(top < 0) return true;
        else return false;
    }
    // length --> return the size of the stack
    int length(){
        return top + 1;
    }
    // print --> print all the elements in the stack
    void print(){
        for(int i = top; i >= 0; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// ? Stack Implementation using Linked list
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class $Stack{
    private:
    Node* head;
    Node* tail;
    int size = 0;
    public:
    $Stack(){
        this->head = NULL;
        this->tail = NULL;
    }
    // functional members
    // push --> insert element at the head of the linked list
    // time complexity --> O(1)
    void push(int data){
        if(this->head == NULL){
            Node* newNode = new Node(data);
            this->head = newNode;
            this->tail = newNode;
            this->size++;
        }else{
            Node* newNode = new Node(data);
            newNode->next = this->head;
            this->head = newNode;
            this->size++;
        }
    }
    // pop --> remove last element from the stack(remove tail from the linked list)
    // time complexity --> this takes time complexity of O(n), where n is the number of nodes in the lineked list
    void $pop(){
        if(head == NULL){
            cout<<"(ERROR) ---> Stack underflowed"<<endl;
            return;
        }
        Node* current = this->head;
        Node* prev = NULL;
        while(current->next != NULL){
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        this->tail = prev;
        size--;
        free(current);
    }
    // better approach for pop(for this we have to keep change the push process instead of adding node at tail insert at head)
    // pop -->
    void pop(){
        if(head == NULL){
            cout<<"(ERROR) ---> Stack underflowed"<<endl;
            return;
        }
        Node* NodeToBeDeleted = this->head;
        this->head = head->next;
        this->size--;
        free(NodeToBeDeleted);
    }
    // top --> last element to enter the stack
    int top(){
        if(size > 0){
            return this->head->data;
        }
        cout<<"(INFO) ---> EMPTY STACK"<<endl;
        return 0;
    }
    // empty --> returns boolean(check whether the stack is empty or not)
    bool empty(){
        if(this->head != NULL) return false;
        else return true;
    }
    // size --> returns the size of the stack
    int length(){
        return this->size;
    }
    // print --> output the data of the stack
    void print(){
        Node* current = this->head;
        while(current != NULL){
            cout<<current->data;
            current = current->next;
            current ? cout<<" <- " : cout<<"";
        }
        cout<<endl;
    }
};

int main(){
    // Stack* s = new Stack(5);
    // s->push(1);
    // s->push(2);
    // s->push(3);
    // s->push(4);
    // s->push(4);
    // s->print();
    // s->pop();
    // s->print();
    // cout<<s->peek()<<endl;
    // cout<<s->empty()<<endl;
    // cout<<s->length()<<endl;

    $Stack* b = new $Stack();
    b->push(1);
    b->push(2);
    b->push(3);
    b->push(202);
    b->push(5);
    b->push(9);
    b->print();
    b->pop();
    b->pop();
    b->print();
    cout<<b->top()<<endl;
    cout<<b->empty()<<endl;
    cout<<b->length()<<endl;
}