// Introduction To Stacks
// ? what is stack data structure?
// --> Stack is a linear data structure which follow the LIFO(last in first out) order / FILO(first in last out) order. A real life example of stack is plates stacked together when the plates are stacked on top of each other, the first plate that one will take away will is the last plate stacked on the stack of plates, though its the last one which was placed but it will be the first one to go.
// ? STL for stack data structure?
// --> <stack> is the pre-processing directory for the stack data structure.
// ? Implementation of stack?
// --> stack can be created either by using the following
// 1. Arrays/Vectors
// 2. Linked List

#include <bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(s.empty() != true){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    // Static allocation of stack
    // stack<type_of_the_data> nameOfStack, type of the data can be both user defined or in-built.
    stack<int> s;
    // The following are in built functions of the stack in STL
    // 1. Insert elements in the stack using push
    // time complexity --> O(1)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    // 2. removing the last element from the stack
    // time complexity --> O(1)
    s.pop();
    print(s);
    // 3. last inserted element in the stack
    // time complexity --> O(1)
    cout<<s.top()<<endl;
    // 4. size of the stack
    // time complexity --> O(1)
    cout<<s.size()<<endl;
    // 5. stack is empty or not
    // time complexity --> O(1)
    cout<<s.empty()<<endl;
    // 6. put element at starting of the stack(just like push_front)
    s.emplace(10);
    print(s);
    s.emplace(20);
    print(s);
}