// @ -----------------double pointers------------------
#include <bits/stdc++.h>
using namespace std;

// void update1(int **p){
//     p = p + 1; //nothing will change here
//     // ? as here we are creating a new local variable named as p which is a copy of p 
// }
// void update2(int **p){
//     *p = *p + 1; //nothing will change here
//     // ? here we are just going to do pointer airthemetic that will increase the mem address by 4 bytes(as it is INT)
// }
void update3(int **p){
    **p = **p + 1; //this will lead to value change
    // ? as we are pointing to change the value pointing to another pointer that will point to the value.
}
int main(){
    // ? The following is the way to create double pointer
    int val = 1010;  //* variable
    int *pointer = &val; //* pointer that will point to val mem address
    int **p2p = &pointer; //* pointer that will point to pointer mem address that will point to val mem address
    // ? we can go even further
    int ***p3p = &p2p; 
    int ****p4p = &p3p;
    // ? lets look at the mem address of each pointer
    cout<<"Memory address of val : "<<&val<<" | parent : "<<"NA"<<endl;
    cout<<"Memory address of val : "<<&pointer<<" | parent : "<<&val<<endl;
    cout<<"Memory address of val : "<<&p2p<<" | parent : "<<&pointer<<endl;
    cout<<"Memory address of val : "<<&p3p<<" | parent : "<<&p2p<<endl;
    cout<<"Memory address of val : "<<&p4p<<" | parent : "<<&p3p<<endl;
    // ? so from the above ouput you can clearly see how the chain works for pointer
    // ? Now, lets look at the values they have
    cout<<"val : "<<val<<endl;
    cout<<"pointer : "<<*pointer<<endl;
    cout<<"p2p : "<<**p2p<<endl;
    cout<<"p3p : "<<***p3p<<endl;
    cout<<"p4p : "<<****p4p<<endl;
    // ? ****p4p --> states that go to p4p there will be a address, take me to that address
    // ? then we will find there another address take me to that address and you will find
    // ? there a address take me to that address and then you will find another address
    // ? take me there and the you will find me the address there and take me there which
    // ? take me to the value of val.
    // ! so the deeper you go in the pointer more you have to use the dereference operator(*)
    // ? if i want to look at the mem address of the pointer from p4p
    // ? i will go p4p will give me the address of p3p 
    // ? *p4p returns the mem address of p2p
    // ? **p4p returns the mem address of pointer
    // ? lets clarify it 
    cout<<&pointer<<endl;
    cout<<**p4p<<endl;

    int i = 777;
    int *p1 = &i;
    int **p2 = &p1;
    // ? there are three ways to get the content inside p1 mem block
    cout<<&i<<"\t"<<p1<<"\t"<<*p2<<endl;
    // cout<<"Before : "<<i<<" "<<p1<<" "<<p2<<endl;
    // update1(p2);
    // cout<<"After : "<<i<<" "<<p1<<" "<<p2<<endl;
    // cout<<"Before : "<<i<<" "<<p1<<" "<<p2<<endl;
    // update2(p2);
    // cout<<"After : "<<i<<" "<<p1<<" "<<p2<<endl;
    cout<<"Before : "<<i<<" "<<p1<<" "<<p2<<endl;
    update3(p2);
    cout<<"After : "<<i<<" "<<p1<<" "<<p2<<endl;
    return 0;
}