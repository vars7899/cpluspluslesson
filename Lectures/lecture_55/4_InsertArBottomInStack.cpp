#include <bits/stdc++.h>
using namespace std;

// Solution use Recursion
// Time complexity --> O(n), where n is the number of elements in the stack
// space complexity --> O(n), as we are taking the call space, as we are calling the insertAtBottom n times.
void insertAtBottom(stack<int> &st, int num){
    // base case
    if(st.empty()){
        st.push(num);
        return;
    }
    int element = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(element);
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
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    int num = 9;
    print(st);
    insertAtBottom(st, num);
    print(st);
}