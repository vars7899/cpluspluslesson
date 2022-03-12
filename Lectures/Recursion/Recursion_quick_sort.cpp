#include <bits/stdc++.h>
using namespace std;

// ! Average T.C = O(n logn)
// ! best case T.C = O(n logn)
// ! worst case T.C = O(n^2)
// ? space complexity = O(n)
void print(vector<int> nums){
    cout<<"[ ";
    for(int item : nums){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}

int partition(vector<int> &nums, int start, int end){
    int pivot = nums[start];
    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(nums[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(nums[start], nums[pivotIndex]);
    
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(nums[i] <= pivot){
            i++;
        }
        while(nums[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(nums[i++], nums[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &nums, int start, int end){
    // base case
    if(start >= end) return;

    // partition
    int p = partition(nums, start, end);

    // sort the rest of the array
    // left part sort
    quickSort(nums, start, p-1);
    // right part sort
    quickSort(nums, p+1, end);
}

int main(){
    vector<int> nums = {22,1,33,3,4,7,9,8};
    print(nums);
    quickSort(nums, 0, nums.size()-1);
    print(nums);
    return 0;
}