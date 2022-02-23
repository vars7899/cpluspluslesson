#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> x){
    for(vector<int> item : x){
        cout<<"[ ";
        for(int t : item){
            cout<<t<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}

vector<vector<int>> getPowerSet(vector<int> inSet){
    // if the given set is empty
    if(inSet.empty()) return {{}};

    vector<vector<int>> outSet = {{}};  

    for(int x : inSet){
        int n = outSet.size();
        for(int j=0; j<n;j++){
            vector<int> mySet = outSet[j];
            mySet.push_back(x);
            outSet.push_back(mySet);
        }
    }
    return outSet;
}

int main(){
    // given set
    vector<int> inSet = {1,2,3};
    vector<vector<int>> outSet = getPowerSet(inSet);
    print(outSet);
}