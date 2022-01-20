#include <bits/stdc++.h>
using namespace std;

pair<int,int> search(vector<vector<int>> matrix,int k){
    pair<int,int> index = {-1,-1};
    // dimesion of the matrix
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    //pointer position in the matrix
    int row = 0;
    int col = numCols - 1;

    while(row<numRows && col >= 0){
        int value = matrix[row][col];
        if(value == k){
            index.first = row;
            index.second = col;
            return index;
        }
        if(value > k){
            col--;
        }else{
            row++;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> matrix = {
        {2,5,10},
        {3,11,15},
        {5,20,28}
    };
    int target = 0;
    pair<int,int> res = search(matrix,target);
    cout<<"["<<res.first<<","<<res.second<<"]"<<endl;

    return 1;
}