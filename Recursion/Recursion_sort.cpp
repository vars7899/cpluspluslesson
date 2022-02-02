#include <bits/stdc++.h>
using namespace std;

// @ ULITIY
void printArr(vector<int> a){
    cout<<"[ ";
    for(int item: a){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}
// @ ULITIY

void selectionSort(vector<int> &nums){
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        int sml=i;
        for(int j=i+1;j<n;j++){
            if(nums[sml] > nums[j]){
                sml = j;
            }
        }
        swap(nums[sml], nums[i]);
    }
}

void selectionSort_recursion(vector<int> &nums,int start, int n){
    // base case
    if(start > n){
        return;
    }
    // swap one item correctly
    int min_idx = start;
    for(int i=start+1;i<n;i++){
        if(nums[min_idx]>nums[i]){
            min_idx = i;
        }
    }
    swap(nums[min_idx], nums[start]);
    // arrange other using recursion
    selectionSort_recursion(nums, start+1, n);

}
int main(){
    vector<int> nums = {22,5,6,99,8,6,7,5,4,3,44,6,4,33,67,2,55,22,1,4};
    // Selection sort
    // --> it select the smallest element and put it in the right place
    selectionSort_recursion(nums,0,nums.size());
    printArr(nums);
}