#include <bits/stdc++.h>
#include "Hero_class.cpp"

using namespace std;

// ? Destructor --> used to deallocate the memory
// The following are the properties of a destructor
// 1. name of the destructor is same as the name of the class
// 2. There is not return in the destructor
// 3. There are no parameter taken for destructor
// 4. it start with ~ tilde sign

// ? objects that are called statically, the destructor are called automatically
// ? for dynamically created object we have to call the destructor manually by using the keyword delete

int main(){
    // static
    Hero h1;
    // dynamic
    Hero *h2 = new Hero();
    delete h2;
    return 0;
}