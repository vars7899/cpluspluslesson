#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main(){
    // memset function
    // It takes three parameters
    // 1. starting point(pointer to the first element of the array)
    // 2. value(data that need to be put in the block of memory)
    // 3. size of the block(give the size of the block)

    int arr[5];
    memset(arr,-1,sizeof(int)*5);
    cout<<sizeof(arr)<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    int* arr1 = new int[5];
    memset(arr1,-1,sizeof(int)*5);
    cout<<sizeof(arr1)<<endl;
    for(int i=0; i<5; i++){
        cout<<arr1[i]<<" ";
    }
}