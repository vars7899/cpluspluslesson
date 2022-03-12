#include <bits/stdc++.h>
using namespace std;

// utility 
// --------------------------------------------
// take 1D array input
void input1D(int arr[], int n){
    // taking input using loop
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
// print 1D array
void print1D(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

// input in 2D array
void input2D(int (*arr)[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
}
// print 2D array
// we will use the argument as (*array name)[column size], this is know as pointer notation
void print2D(int (*arr)[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
// --------------------------------------------
int main(){
    // decalaration in arrays
    int arr[10]; //linear array with 10 elements
    // creating 2D arrays in the cpp
    int arr2[3][4]; // create 2D array with 3 row and 4 columns

    // declaring and intializing 2D arr
    int arr3[3][3] = {1,2,3,4,5,6,7,8,9};
    print2D(arr3);
    // the above will look like the following matrix
    // 1,2,3
    // 4,5,6
    // 7,8,9
    // so the elements are going in row sequence first row is added then second and so on.
    int arr4[3][3] = {{1,2,1},{1,2,1},{1,2,1}};
    print2D(arr4);


    // 1D array
    int a1[3];
    // calculating the size of array
    int n = sizeof(a1)/sizeof(int);
    // input in linear array
    // input1D(a1,n);
    // output in linear array
    // print1D(a1,n);

    // 2D arrays
    int a2[3][3]; //array with 3 rows and 3 columns
    // taking input using two loop

    // input int 2D array
    input2D(a2);
    // output int 2D array
    print2D(a2);

}