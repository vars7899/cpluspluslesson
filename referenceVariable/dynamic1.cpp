#include <bits/stdc++.h>
using namespace std;

// ? dynamic memory --> using the heap memory
// ? static memory --> using the stack memory

int main(){
    // ! why passing the size of array at runtime is a bad practice?
    // int n;
    // cin>>n;
    // int arr[n];
    // ! passing a user defined size of array is a BAD PRACTICE
    // ? It is a bad practice to declare the size of array at run time, as whenever a program runs some memory is allocated to it(two types of memory stack memory and heap memory), and this stack memory is dependent on the compile time environment, if the compiler says that to run this program i will give 4bytes of stack memory and at runtime the user passed that he/she want a array of size 4 that will have a mem size of 16bytes but we can not store it as we do not have enough stack memory. So, the program will crash. 

    // ! what if i want to allocate an array in the run time
    // ? we will use the heap memory or dynamic memory allocation
    // ? we can assign a variable in heap memory using the new keyword but we cannot assign a name to this variable, so we use pointer in this case
    char *ch = new char; //* as new char will return a memory address 
    // ? now lets create a dynamic allocated array
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    // ! static memory has automatic memory release but heap memory doesnot have this manually delete
    delete []arr;
}