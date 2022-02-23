#include <bits/stdc++.h>
using namespace std;

// @ UTILITY
void print(vector<int> a){
    cout<<"[ ";
    for(int item : a){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}


void merge(vector<int> &nums, int start, int end){
    // calculate the mid of the array
    int mid = start + (end-start)/2;
    // length of first array
    int length1 = mid - start + 1;
    int length2 = end - mid;
    // Create new dynamic array to make copies of array
    int *arr1 = new int[length1];
    int *arr2 = new int[length2];

    // copy all the elements from original array to these two sub arrays
    int point = start;
    for(int i=0;i<length1;i++){
        arr1[i] = nums[point];
        point++; //move to next element
    }
    point = mid + 1;
    for(int i=0;i<length2;i++){
        arr2[i] = nums[point];
        point++;
    }

    // merge two sorted arrays
    int pointer1 = 0;
    int pointer2 = 0;
    point = start; //reset to start value
    while(pointer1<length1 && pointer2<length2){
        if(arr1[pointer1] > arr2[pointer2]){
            nums[start++] = arr2[pointer2++];
        }else{
            nums[start++] = arr1[pointer1++];
        }
    }
    while(pointer1<length1){
        nums[start++] = arr1[pointer1++];
    }
    while(pointer2<length2){
        nums[start++] = arr2[pointer2++];
    }
    // delete the dynamic arrays
    delete []arr1;
    delete []arr2;
}

void mergeSort(vector<int> &nums, int start, int end){
    // Base case
    // when array length is 0 or
    // if the array has only one element it is sorted
    if(start >= end) return;
    //compute the mid of the array
    int mid = start + (end - start)/2;
    //sort the left side of the array
    mergeSort(nums, start, mid);
    // sort the right side of the array
    mergeSort(nums, mid+1, end);

    // function to merge these array back
    merge(nums, start, end);
}

int main(){
    vector<int> sample = { 22,33,11,44,55,77,88,1010,1,2,5,8,2,35,6,7,67};
    mergeSort(sample, 0, sample.size()-1);
    print(sample);
}
