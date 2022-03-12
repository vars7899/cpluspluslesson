#include <bits/stdc++.h>
using namespace std;

int search2D(vector<vector<int>> matrix, int target){
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int low = 0;
    int high = numRows*numCols - 1;
    while(low<=high){
        int mid = low + (high - low)/2;
        int midValue = matrix[mid/numCols][mid%numCols];
        if(midValue == target){
            return mid;
        }else if(midValue > target){
            high = mid - 1;
        }else{
            low =  mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<vector<int>>arr = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
        };
    int target = 300;
    cout<<search2D(arr,target);
    return 1;
}