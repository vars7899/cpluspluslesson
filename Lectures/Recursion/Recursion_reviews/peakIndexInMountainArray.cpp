#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &nums){
    int start = 0;
    int end = nums.size() - 1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(nums[mid] < nums[mid+1]){
            start = mid +1;
        }else{
            end = mid;
        }
    }
    return start;
}

int main(){
    vector<int> nums = {0,10,5,2};
    // If we look from the peak there will be two sorted arrays
    // one that is sorted in increasing order and the other which
    // is sorted in the decreasing order
    cout<<findPeak(nums);
}