#include <bits/stdc++.h>
using namespace std;

// @ UTILITY
void print(vector<int> a){
    cout<<"[ ";
    for(int item : a){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}
// @ UTILITY

void insertionSort(vector<int> &nums, int n){
    int key;
    // Go though each element in the unsorted array
    for(int i=1;i<n;i++){
        key = nums[i];
        int j = i-1;
        while(j>=0 &&  nums[j]>key){
            print(nums);
            nums[j+1]=nums[j];
            j=j-1;
        }
        nums[j+1]=key;
        print(nums);
    }
}

int main(){
    vector<int> nums = {4,9,8,5,4,3,0};
    // Selection sort
    // --> it select the smallest element and put it in the right place
    insertionSort(nums,nums.size());
    print(nums);

}