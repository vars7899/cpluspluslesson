#include <bits/stdc++.h>
using namespace std;

// Delete the middle element from a stack, for example
// stack<int> st = [1,2,3,4,5], N = 4
// middle element is N/2 = 2, so remove 3 from stack.
void deleteM(stack<int> &st, int N, int ptr){
    // base case
    // when we are at middle of the stack
    if(ptr == N/2){
        st.pop();
        return;
    }
    // remove the top of the stack and give the rest of stack to recursion to find out the middle
    int element = st.top();
    st.pop();
    deleteM(st, N, ptr+1);
    // add the elements which were at top of middle
    st.push(element);
    return;
}
void deleteMiddle(stack<int> &st, int N){
    int ptr = 0;
    deleteM(st, N, ptr);
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
    int N;
    cin>>N;
    for(int i = 0; i <= N; i++){
        int item;
        cin>>item;
        st.push(item);
    }
    deleteMiddle(st, N);
    print(st);
}