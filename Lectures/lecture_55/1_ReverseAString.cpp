#include <bits/stdc++.h>
using namespace std;

// Reverse a String --> There are multiple approaches to solve this problem of reversing a string.
// 1. Using SWAP method --> we can use the two pointer one pointing to the first character of the string and the other one at the last character of the string and we will swap the data of these two pointer and keep on iterating until the first pointer pass the second pointer.
// ? Time complexity --> O(n), where n is the number of nodes in the string
// ? space complexity --> O(1), constant space
string reverseUsingSwap(string str){
    int i = 0;
    int j = str.length();
    while(i <= j){
        swap(str[i], str[j]);
    }
    return str;
}

// 2. Using STACK method --> property of stack is that it always reverse whatever is ent to it.
// . STACK property is that it reverse anything given to it.
// ? time complexity --> O(n), where n is the number of character in the string
// ? space complexity --> O(n), where n is the number of character in the string
string reverseUsingStack(string str){
    string response = "";
    stack<char> st;
    // create a stack to store character;
    // insert all the character of the string
    for(int i=0; i<str.length(); i++){
        st.push(str[i]);
    }

    // take out the character one by one
    while(!st.empty()){
        response.push_back(st.top());
        st.pop();
    }

    return response;
}


int main(){
    string str = "";
    cout<<"Enter the string :";
    cin>>str;
    cout<<reverseUsingStack(str);
}
