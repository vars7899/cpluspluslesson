#include <bits/stdc++.h>
using namespace std;

void print(vector<int> nums){
    cout<<"[ ";
    for(int item : nums){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}

void merge(vector<int> &nums, int start, int end){
    // calculate the mid of array
    int mid = start + (end - start)/2;
    // length of each array
    int length1 = mid - start + 1;
    int length2 = end - mid;
    // create two dynamic arrays
    int *nums1 = new int[length1];
    int *nums2 = new int[length2];
    // copy all the elements of the first array
    int pointer = start;
    for(int i=0;i<length1;i++){
        nums1[i] = nums[pointer++];
    }
    // copy all the elements of the second array
    pointer = mid + 1;
    for(int i=0;i<length2;i++){
        nums2[i] = nums[pointer++];
    }
    // merge these two arrays and sort them
    int point1 = 0;
    int point2 = 0;
    pointer = start; //reset its value
    while(point1 < length1 && point2 < length2){
        if(nums1[point1] > nums2[point2]){
            nums[pointer++] = nums2[point2++];
        }else{
            nums[pointer++] = nums1[point1++];
        }
    }
    // if one array still has element inside it
    // dump all the remaining elements
    while(point1 < length1){
        nums[pointer++] = nums1[point1++];
    }
    
    while(point2 < length2){
        nums[pointer++] = nums2[point2++];
    }
    // free up the heap memory
    delete []nums1;
    delete []nums2;
}

void merge_sort(vector<int> &nums,int start, int end){
    // base case
    // if the array has only one element it is sorted
    // or if the array has no element it is sorted as well
    if(start >= end) return;
    // calculate the mid of array
    int mid = start + (end - start)/2;
    // sort the left part of array
    merge_sort(nums, start, mid);
    // sort the right part of the array
    merge_sort(nums, mid+1,end);
    // merge the arrays
    merge(nums, start, end);
}

int main(){
    vector<int> nums = {
        44,77,11,33,22,55,44,77,88,99,33
    };
    print(nums);
    merge_sort(nums,0,nums.size());
    print(nums);
    return 0;
}