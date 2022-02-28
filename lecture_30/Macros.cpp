#include <bits/stdc++.h>
using namespace std;

// ? Macro
// ? Macro is a piece of code in a program that is replaced by the content of macro
// ? There are three types of macros
// ? 1. object like macros
// ? 2. chain like macros
// ? 3. function like macros



#define pi 3.14 // * this is a type of object-like macro 
// * This fragment of code will be replaced the content of macro
// ? we can also define multiline comment
// ? in order to create a multiline macro we have to backslash
#define ARR 1, \
            2, \
            3
// * The above line of code will be replaced by the array

// ? Macros inside macros are known as chain-like macros
#define fullname first_name last_name
#define first_name "Vaibhav"
#define last_name " Dhiman"
// * In the above lines we have defined a macro named fullname which consist of two macro first_name and last_name and we have defined each of them.
 
#define SUM(a,b) (a+b) 
// * The above line of code is a type function-like macro
// * This fragment of code will replace SUM(n,m) with the content of the macro which is (n+m)

void circle(int radius){
    // circumference
    int circum = 2*pi*radius;
    // area
    int area = pi*radius*radius;
    cout<<"Circumference of circle : "<<circum<<endl;
    cout<<"Area of circle : "<<area<<endl;
}

int main(){
    // int n;
    // cin>>n;
    // circle(n);
    int myArr[] = {ARR};
    for(int item: myArr){
        cout<<item<<" ";
    }cout<<endl;
    cout<<fullname<<endl;
    int n,m;
    cin>>n>>m;
    int res = SUM(n,m);
    cout<<res<<endl;
}