#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int mini;
    stack<int> st;

    public:
    void push(int data){
        // check for overflow
        
        // for the first element(normal push)
        if(st.empty()){
            st.push(data);
            mini = data;
        }else{
            if(data<mini){
                int value = 2*(data) - mini;
                st.push(value);
                mini = data;
            }else{
                st.push(data);
            }
            
        }
    }
    int pop(){
        int current = st.top();
        if(st.empty()){
            return -1;
        }

        if(current < mini){
            int p_mini = mini;
            int value = (2*mini) - current;
            mini = value;
            st.pop();
            return p_mini;
        }else{
            st.pop();
        }

        return current;
    }
    int top(){
        if(st.empty()) return -1;

        int current = st.top();
        if(current < mini){
            return mini;
        }else{
            return current;
        }
    }
    bool isEmpty(){
        return st.empty();
    }
    int getMin(){
        if(st.empty()){
            return -1;
        }
        return mini;
    }
};

int main(){

}