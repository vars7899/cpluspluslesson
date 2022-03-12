// preprocessor directive
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int start, int end){
    int pivot = nums[start];
    int count = 0;
    // count the number of smaller element
    for(int i = start+1; i<=end; i++){
        if(nums[i] <= pivot) count++;
    }
    // place the pivot element at right position
    int pivotIndex = start + count;
    swap(nums[start], nums[pivotIndex]);

    // all the elements on the left should be smaller than 
    // pivot element and all the element on the right should
    // be greater than pivot element
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(nums[i] <= pivot) i++;
        while(nums[j] > pivot) j--;
        if(i < pivotIndex && j > pivotIndex) swap(nums[i++], nums[j--]);
    }

    return pivotIndex;
}

void quickSort(vector<int> &nums, int start, int end){
    // base case 
    if(start >= end) return;

    // get the pivot index of the array
    int p = partition(nums, start, end);
    // ? sort the left side from partition
    quickSort(nums, start, p-1);
    // ? sort the right side from partition
    quickSort(nums, p+1, end);
}

// ? utility -- print array
void printArray(vector<int> nums){
    cout<<"[ ";
    for(int item : nums){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}

int main(){
    vector<int> nums = {2,8,9,1,2,5,3,2,1};
    int n = nums.size();
    printArray(nums);
    quickSort(nums, 0, n-1);
    printArray(nums);
}