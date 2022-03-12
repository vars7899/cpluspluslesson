#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void reverse(int arr[], int index, int size){
    if(index >= size/2) return;
    swap(arr[index], arr[size -index - 1]);
    reverse(arr, index + 1, size);
}
bool isPalindrome(char str[], int index, int size){
    // base case
    if(index >= size/2) return true;
    // process
    if(str[index] != str[size-index-1]) return false;
    return isPalindrome(str,index+1,size);
}
int main(){
    // ! reverse an array
    // ? what we usually do to swap the array is to use a loop and swap element at ith position with the element at n-ith position
    // ? how can we solve the same problem using the recursion
    int arr[] = {1,2,3,4,5};
    reverse(arr, 0,5);
    print(arr, 5);
    char word[] = "MADAME";
    cout<<isPalindrome(word, 0, 6);

}