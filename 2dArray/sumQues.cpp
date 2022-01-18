#include <bits/stdc++.h>
using namespace std;

void print1D(vector<int> arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

// row-wise sum in 2D arr
void rowSum(int (*arr)[5], int r, int c){
    vector<int> ans;
    int sum = 0;
    for(int row=0;row<r;row++){
        for(int col=0;col<c;col++){
            sum += arr[row][col];
        }
        ans.push_back(sum);
        sum = 0;
    }

    print1D(ans);
}

// col-wise sum in 2D arr
void colSum(int (*arr)[5], int r, int c){
    vector<int> ans;
    int sum = 0;
    for(int col=0;col<c;col++){
        for(int row=0;row<r;row++){
            sum += arr[row][col];
        }
        ans.push_back(sum);
        sum = 0;
    }

    print1D(ans);
}

// largest row sum
void largestRowSum(int (*arr)[5], int r, int c){
    int index;
    int max = INT_MIN;
    for(int row=0;row<r;row++){
        int sum = 0;
        for(int col=0;col<c;col++){
            sum += arr[row][col];
        }
        if(sum > max){ 
            max = sum;
            index = row;
        }
    }
    cout<<index;
}

int main(){
    int arr[4][5] ={{1,2,3,4,5},{5,6,7,8,9},{1,2,3,4,5},{5,6,7,8,10}};
    rowSum(arr,4,5);
    colSum(arr,4,5);
    largestRowSum(arr,4,5);
}