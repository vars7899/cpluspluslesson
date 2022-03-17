#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int item){
    // base case
    if(st.empty()){
        st.push(item);
        return;
    }

    int element = st.top();
    st.pop();

    insert(st, item);

    st.push(element);
    return;
}
// time complexity --> O(n^2)
// space complexity --> O(n)
void reverseStack(stack<int> &st){
    // base case
    // if stack is empty
    if(st.empty()) return;

    int element = st.top();
    st.pop();

    // recursive call
    reverseStack(st);

    insert(st, element);
}
void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    print(st);
    reverseStack(st);
    print(st);
}