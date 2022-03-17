#include <bits/stdc++.h>
using namespace std;

// Time complexity --> O(n), where n is the number of chareacter in the string 
// Space complexity --> O(n), where n is the number of character in the string(this is worst case for example given string is "{{{{{{{{{{{[[[[{{" )
bool isValidParenthesis(string expression){
    // stack
    stack<char> st;

    for(int i=0; i<expression.length(); i++){
        char item = expression[i];
        // if opening bracket, add it to the stack
        if(item == '[' || item == '(' || item == '{'){
            st.push(item);
        }else{
            // check if something is there is stack
            if(!st.empty()){
                // check if closing bracket is available
                char top = st.top();
                if((top == '(' && item == ')') || (top == '{' && item == '}') || (top == '[' && item == ']')){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                // first we found the closing bracket
                return false;
            }
        }
 
    }
    // empty stack will be returned if parenthesis are valid
    if(st.empty()){
        return true;
    }else return false;
}
int main(){
    string expression = "[()]{}{[()()]()}";
    cout<<isValidParenthesis(expression);
}