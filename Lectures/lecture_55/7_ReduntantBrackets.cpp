#include <bits/stdc++.h>
using namespace std;
// Time complexity --> O(n), where n is the number of character in the string.
bool checkRedundancy(string str){
    // create stack
    stack<char> st;

    for (int i = 0; i < str.length(); i++){
        char first = str[i];
        if (first == '(' || first == '+' || first == '-' || first == '*' || first == '/'){
            st.push(first);
        }
        else
        {
            if(first == ')'){
                bool isRedundant = true;
                while (st.top() != '('){
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true) return true;
                st.pop(); // to remove the opening bracket
            }
        }
    }
    return false;
}

int main(){
    string str = "((a+b))";
    cout << checkRedundancy(str) << endl;
}