#include <bits/stdc++.h>
using namespace std;
int main(){
    // ? the name of the array actually points to the memory location
    int arr[5] = {0};
    cout<<"Memory address of first element : "<<arr<<endl;
    // ? another way to get the memory location in array is to use the address of operator(&)
    cout<<"Memory address of first element : "<<&arr[0]<<endl;

    // ? get the address of the whole array
    cout<<"---------------------------------------------------------"<<endl;
    for(int i=0;i<5;i++){
        cout<<"Memory address of "<< i <<" element : "<<&arr[i]<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;

    // * now we will be using pointers in array
    int a[9] = {1,2,3,4,5,6,7,8,9};
    cout<<"*a : "<<*a<<endl; // returns the value stored in index 0
    // ! what will happen if we do *a + 1?
    // * --> it will get the value from the array a at index 0 than add 1 to that value
    // * here the answer will be 2(1+1);
    cout<<"*a+1 : "<<*a+1<<endl;
    // ! what will happen if we do *(a + 1)?
    // * --> here a is pointing to first element + 1 will move the pointer to next index
    // * in answer we will get 2(a[1]);
    cout<<"*(a+1) : "<<*(a+1)<<endl; 

    // ! how the getting the element from the array work
    // * under the hood the arr[i] use the pointer *(arr + i)
    cout<<"a[5] : "<<a[5]<<endl; // element at the fifth index
    cout<<"*(a+5) : "<<*(a+5)<<endl; // element at the fifth index
    // * so we can also write *(5+a) it will give the same result 6
    // * but we can also write it as 5[a], will it work?
    // * --> yes it will work as under the hood the implementation is using the pointer which is proper here
    cout<<"5[a] : "<<5[a]<<endl; // ! important

    // ? getting size of whole array vs single element
    int b[5] ={23,23,12,34,0};
    cout<<"size of whole array : "<<sizeof(b)<<endl;
    // ? the above will return 20 as 5 elements with each size of 4(sizeof(INT))
    cout<<"size of one element : "<<sizeof(*b)<<endl;
    // ? the above will return 4 

    // ? more about the pointers in array
    int my_array[10] = {1,2,4,2,23,32,5,2,2,2};
    // * all of the following will give the memory address of the first element
    cout<<"memory address : "<<my_array<<endl;
    cout<<"memory address : "<<&my_array<<endl;
    cout<<"memory address : "<<&my_array[0]<<endl;

    // ? lets make a pointer for the first element in the array
    int *ptr = &my_array[0];
    cout<<&ptr<<" -- is the memory address of pointer itself"<<endl;
    cout<<*ptr<<" -- will give the value stored in pointer"<<endl;
    cout<<ptr<<" -- will return memory address of the item stored in pointer"<<endl;

    // * pointer airthemetic in array
    ptr = ptr + 2; //! we have simply moved our pointer from 0th index to the 2nd index 
    // should return 3rd element --> 4
    cout<<*ptr<<endl;

    // @

}