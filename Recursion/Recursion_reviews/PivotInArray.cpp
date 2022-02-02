#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> nums){
    int start=0;
    int end = nums.size()-1;
    while(start<end){
        int mid = start + (end -start)/2;
        if(nums[mid] < nums[0]){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
}
int findPivot_recursion(vector<int> nums, int start, int end){
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(start == end) return mid;
    if(nums[mid] >= nums[0]){
        return findPivot_recursion(nums, mid+1, end);
    }else{
        return findPivot_recursion(nums, start, mid);
        // if(rem == -1) return mid;
        // else return rem;
    }
}
int main(){
    vector<int> nums = {1,2,3};
    cout<<findPivot_recursion(nums,0,nums.size()-1);
}