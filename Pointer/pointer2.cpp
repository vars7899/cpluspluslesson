// ! what is pointer?
// * It is a variable to store the memory location of another variable
// ! what are the diffrent types of pointer? 
// * different types of pointer in cpp
// * 1. null pointer
// * 2. double pointer
// * 3. void pointer
// * 4. wild pointer
// * 5. dangling pointer

#include <bits/stdc++.h>
using namespace std;

void null_pointer(){
    // ? null pointer are the pointer that just points to no memory address/no variable
    int *ptr1 = NULL; 
    int *ptr2 = 0;
    // ? both passing NULL or 0 will create a null pointer
}
void double_pointer(){
    // ? double pointer is used to point to the memory address of another pointer
    // ! ** is used for double pointer
    int val = 32;
    int *ptr1 = &val; 
    int **ptr2 = &ptr1; 
    // ? here we have created a pointer that is pointing to the value of val
    // ? and we have created another pointer that is pointing to the value stored in
    // ? pointer 1 that is value of val
}
void void_pointer(){
    // ? void pointer is a pointer that has type of void
    int val = 20;
    void *ptr = &val;
    // ? created a null pointer that is pointing to value of val
    // ! key things to know about the void pointer 
    // ! 1. it cannot be dereferenced
    // ! 2. pointer airthemetic is not possible on void pointer
}
void wild_pointer(){
    // ? wild pointer is a bad practice and it is a pointer which is pointing to random memory address
    // ? wild pointer is created when we declare a pointer but do not initialize it
    int *ptr;
    cout<<"value : "<<ptr<<endl; //everytime we run the code the value stored in value will be different and will be any garbage value
}
void dangling_pointer(){
    // ? dangling pointer is a pointer which is pointing to a memory address that is already been freed up
    vector<int> v = {1,2,3,4,5,6};
    // ?lets create a pointer that points to v[v.end()]
    int *pointer = &v[5];
    cout<<*pointer<<endl;
    // ? now lets delete the v[5]
    v.pop_back();
    cout<<*pointer<<endl; // ? now this line is pointing to a mem address where it used to have v[5]


}
int main(){
    null_pointer();
    double_pointer();
    void_pointer();
    wild_pointer();
    dangling_pointer();
    return 0;
}