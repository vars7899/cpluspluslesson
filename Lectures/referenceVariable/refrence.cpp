#include <bits/stdc++.h>
using namespace std;

// * The following function recives a paramete n which is passed by value. So, here we will create a copy of n and store its value in a new variable, and if we make any changes it will not effect the n as changes are made to the copy of n which is k.
void update(int k ){
    k++;
}
// * The following function use the pass by reference, we create a variable name that points to the same value, if we make any changes to the k the changes will be done to n, as it is the same variable with different names
void update2(int &k){
    k++;
}
// ? we can also return a reference variable from a function, the following is the syntax used to show that this function will return a reference variable(BAD PRACTICE)
// ! this function will give us a warning as we did not looked at the scope of variable we create.
// * scope of a --> local within func
// * scope of ans --> local within func
// * scope of res --> local within func
// * if we try to return a local variable the complier will give us a warning
int& func(int a){
    int ans = a; // * we got a value(pass by value) and intialized ans with the value of a  
    int &res = ans; // * we created a reference variable for ans
    return res; // * returned the reference variable
}

int main(){
    // ? Reference variable --> Another name for a already existing variable is known as reference variable or different variable name pointing to the same memory address
    int first = 1010;
    int &second = first;
    // * Above we have created a reference variable for first, named as second
    // * As, both of them are pointing to the same memory location, we have the capabilty to perform CRUD on it using either name
    first++; // 1010 + 1 = 1011 
    second++; // 1011 + 1 = 1012
    cout<<first<<" "<<second<<endl;
    // ! why do we need reference variable?
    // ? 
    int n = 5;
    cout<<"Pass by Value ---------------"<<endl;
    cout<<"Before : "<<n<<endl;
    update(n);
    cout<<"After : "<<n<<endl;
    cout<<"Pass by Reference ---------------"<<endl;
    cout<<"Before : "<<n<<endl;
    update2(n);
    cout<<"After : "<<n<<endl;
}