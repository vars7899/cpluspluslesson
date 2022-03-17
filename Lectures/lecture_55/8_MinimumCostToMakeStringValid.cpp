#include <bits/stdc++.h>
using namespace std;

void print(stack<char> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
    }
    cout<<endl;
}
int checkCost(string str){
    // if the string has odd number of brackets
    // then, you cannot make the string valid 
    // after any number of changes in bracket
    if(str.length()&1 == 1) return -1; 
    
    stack<char> st;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(ch == '{' ){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    int openBracketCount = 0;
    int closeBracketCount = 0;
    while(!st.empty()){
        if(st.top() == '{') openBracketCount++;
        else closeBracketCount++;

        st.pop();
    }

    int ans = (openBracketCount+1)/2 + (closeBracketCount+1)/2;
    return ans;
}


int main(){
    string expression = "}}}}";
    cout<<checkCost(expression);
}