#include <bits/stdc++.h>
using namespace std;

void arrayElem(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void sumArr(int *arr,int size, int &sum){
    int i = 0;
    while(i<size){
        sum += arr[i++];
    }
}
int main(){
    // create a 1D dyn alloc array
    // int size;
    // cin>>size;
    // int *array = new int[size];
    // arrayElem(array,size);
    // printArr(array,size);
    // int sum = 0;
    // sumArr(array,size,sum);
    // cout<<sum;
    // // free up the heap mem
    // delete []array;

    // create a 2D dyn alloc array
    int row,col;
    cin>>row>>col;
    int **arr = new int*[row];
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    // taking input in 2D
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    // print the 2D array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //free up the memory
    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete [] arr;

    // create jaggered array

}