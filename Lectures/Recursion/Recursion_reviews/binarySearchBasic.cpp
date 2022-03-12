#include <bits/stdc++.h>
using namespace std;
// using loops
int binarySearch(int arr[],int size, int key){
    int start = 0; 
    int end = size - 1;
    while(start <= end){
        // compute mid
        int mid = start + (end - start)/2;
        // if the value present at the mid position is equal to key return index
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            // if the value present at mid position is greater than the key, as the array is sorted all the values on the right will also be greater than the key
            // So, Look in the left side
            end = mid - 1;
        }else{
            // look in the right side
            start = mid + 1;
        }
    }
    // if key is not present return -1
    return -1;
}
//using recursion
int binarySearch(int arr[],int start, int end, int key){
    // base case
    // we have gone through the whole array and
    // still did not found the key, it means the
    // key doenot exist in the array 
    if(start > end) return -1;
    // compute the mid
    int mid = start + (end - start)/2;
    // if the key found return the index
    if(arr[mid] == key) return mid;
    if(arr[mid] > key){
        // All the elements in the right will be greater
        // than the key as we are working with sortted
        // arrays
        return binarySearch(arr, start, mid-1, key);
    }else{
        // All the elements in the left are smaller,
        // as it is sorted array so Look in the right
        // part of array
        return binarySearch(arr, mid+1, end, key);
    }
}
int main(){
    // For binary search the array has to be sorted
    int arr[] = {22,45,67,89,103,567,568,601}; 
    int size = 8;
    int key = 568; // search key inside arr[]
    cout<<binarySearch(arr, size, key)<<endl;
}