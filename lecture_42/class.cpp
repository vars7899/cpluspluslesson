#include <bits/stdc++.h>
#include "Creating_class_in_different_file.cpp" // for the hero class
using namespace std;

// class --> it is a user defined data type
// we have in-built data types like bool, int, long etc we can also define custom data type using classes

// ? chair is a user defined data type that will have some properties and behaviour
class chair{
    // the following are the properties
    // we can have as many properties as we want as it is a user defined data type
    int height; // size --> 4 bytes
    int width; // size --> 4 bytes
    int length; // size --> 4 bytes
    char brand[20]; // size --> 20 x 1 byte
    // the total size of the chair class should be 32 bytes
};
// ! what is there is an object with no properties what will be its size
// ? 1 byte
// ? it comes out to be 1 as the compiler says that ou dont have any property but still i will give you 1 byte just as an identifier
class emptyObj{
    //no properties 
};

int main(){
    // intantiate a chair object
    chair ch1;
    cout<<sizeof(ch1)<<endl;
    // intantiate a empty object
    emptyObj em1;
    cout<<sizeof(em1)<<endl;
    Hero h1;
}