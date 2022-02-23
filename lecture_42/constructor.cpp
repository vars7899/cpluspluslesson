#include <bits/stdc++.h>
using namespace std;

class Hero{
    // when we do not write the constructor
    // the complier automatically creates a default constructor
    // ? the following are the properties of a constructor
    // 1. the name of the constructor is same as the name of the class
    //  2. there is no type of the constructor
    //  3. there are no parameter of the constructor
    //  4. it is invoked at the time of object creation
    public:
    Hero(){
        cout<<"Constructor is called"<<endl;
    }
};

int main(){
    // object initializing statically
    Hero Thor;
    // object intialized dynamically
    Hero *Arrow = new Hero();


}

// class is user defined data type or custom data type, which has its own data members and function members, which can be accessed by creating an instance of the class. Class is like the blue print for an object.
// object --> it is an identifiable entity which has properties and behaviour.
// access modifiers --> there are three access modifier 
// public --> the data members or function members can be accessed within the class or outside the class
// private --> the data members or function members can only be accessed within the class or by sub class
// protected -->
// by default if we do not write the access type, it becomes protected.
// object 