#include <bits/stdc++.h>
using namespace std;

// -------- Global Variable ------
// when you want to share a variable among different function, you create a global variable with global scope
int BUFFER = 1024;
// here in the above line we have created a global variable of integer type whose value is equal to 1024 in the memory

// pass by reference method
void add2(string &s){
    cout<<BUFFER<<endl;
    s += " pass by reference";
}
void add1(string &s){
    cout<<BUFFER<<endl;
    s += " is";
    add2(s);
}

int main(){
    // Instead of using global variable we can also use the pass by reference method
    // the following example shows that
    string scope = "This";
    add1(scope);
    cout<<scope<<endl;
}