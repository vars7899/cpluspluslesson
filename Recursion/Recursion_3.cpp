// recurision with arrays
#include <bits/stdc++.h>
using namespace std;

bool checkUsingLoops(int v[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(v[i]>v[j]) return false;
        }
    }
    return true;
}
bool checkUsingRecursion(int *v, int size){
    // base case
    if(size == 0 || size == 1){
        // As if the array is empty, then it is sorted
        // if array has only one element it is sorted
        return true;
    }
    if(v[0] > v[1]) return false;
    else {
        bool rem = checkUsingRecursion(v+1, size-1);
        return rem;
    }

}
int sumArrayUsingRecursion(int *arr, int size){
    int sum = 0;
    if(size == 0) return 0;
    if(size == 1) return arr[0];
    else{
        sum = arr[0] + sumArrayUsingRecursion(arr+1, size-1);
    }
    return sum;
}
int linearSearchUsingrecursion(int *arr, int size, int key){
    // ? base case --> if the size of array is zero, there should be no element in array. So, return false.
    if(size == 0) return false;
    // ? base case --> if the array first element is equal to the key. So, return true
    if(arr[0] == key) return true;
    else{
        bool rem = linearSearchUsingrecursion(arr+1,size-1,key);
        return rem;
    }
}
int binarySearchUsingRecursion(int *arr, int start, int end, int key){
    // base case
    if(start > end) return -1;

    int mid = start + (end - start)/2;

    if(arr[mid] == key) return true;
    // process the mid
    if(arr[mid] > key){
        return binarySearchUsingRecursion(arr,start,mid-1,key);
    }else{
        return binarySearchUsingRecursion(arr,mid+1,end,key);
    }
}
int main(){
    //  Q1 check if a given array is sorted or not
    int myArr[] = {2,4,5,19,89,790};
    int size = 5;
    cout<<checkUsingLoops(myArr, size)<<endl; //? soln using loops
    cout<<checkUsingRecursion(myArr, size)<<endl; //? soln using recursion
    cout<<sumArrayUsingRecursion(myArr, size)<<endl;
    cout<<linearSearchUsingrecursion(myArr, size, 4)<<endl;
    cout<<binarySearchUsingRecursion(myArr, 0, size-1, 90)<<endl;
}