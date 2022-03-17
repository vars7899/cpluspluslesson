#include <bits/stdc++.h>
using namespace std;

void sortAdd(stack<int> &st, int element){
    // base case --> if the stack is empty
    if(st.empty() || (!st.empty() && st.top() <= element)){
        st.push(element);
        return;
    }

    int item = st.top();
    st.pop();

    // recursive call
    sortAdd(st, element);

    // add rest of the element at the top
    st.push(item);
}
// Time complexity --> O(n^2), where n is the number of stack items
// space complexity --> O(n)
void sortStack(stack<int> &st){
    // base case
    if(st.empty()) return;

    // get the top element
    int element = st.top();
    st.pop();

    sortStack(st);

    // add element but in sorted way
    sortAdd(st, element);
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
    st.push(5);
    st.push(-7);
    st.push(9);
    st.push(-7);
    st.push(3);
    sortStack(st);
    print(st);
}