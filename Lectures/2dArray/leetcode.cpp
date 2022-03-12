#include <bits/stdc++.h>
using namespace std;

void print2D(vector<int> arr){
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> ans;
    for(int col=0;col<mCols;col++){
        if(col&1){
            for(int row=nRows;row>0;row--) ans.push_back(arr[row][col]);
        }else{
            for(int row=0;row<nRows;row++) ans.push_back(arr[row][col]);
        }
    }
    print2D(ans);
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{1,2,3,4},{5,6,7,8}};
    wavePrint(arr,4,4);
}

