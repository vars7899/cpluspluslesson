#include <bits/stdc++.h>
using namespace std;

// function overloading --> making multiple function with same name is known as function overloading.
// we can not have two function with same name and just change in the return type, the compiler will give you an error

class A{
    public:
    void print(){
        cout<<"GGG"<<endl;
    }
    void print(string str){
        cout<<str<<endl;
    }

    // The following is not function overloading as only the return type is chaged other things are just same

    // int print(){
    //     cout<<"DDD"<<endl;
    //     return 1;
    // }

    int print(char ch){
        cout<<ch<<endl;
        return 1;
    }
};

// operator overloading


int main(){

}