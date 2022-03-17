#include <bits/stdc++.h>
using namespace std;
// Next smaller element, the question is tha you are given an array with N elements and your job is to return the elements next smaller element, for example
// arr = [2,3,1,4] so ans is 1 1 -1 -1
// explanation --> for 2 next smaller element should lie between [3,1,4], 3 is greater than 2 ignore move to next 1 is smaller than 2 store it and check if a number smaller than 1 exist until the array have element.

// time complexity --> O(n^2), where n is the number of elements in the input array, n^2 as we are traversing through array with two pointers.
// space complexity --> O(n), constant time.
// vector<int> nextSmallerElement(vector<int> & arr, int n){
//     // create new vector to store ans
//     vector<int> ans(arr);

//     for(int i=0; i<arr.size(); i++){
//         for(int j=i; j<arr.size(); j++){
//             if(arr[j] < arr[i]){
//                 ans[i] = arr[j];
//                 break;
//             }
//             ans[i] = -1;
//         }
//     }
//     return ans;
// }
// Better Approach

vector<int> nextSmallerElement(vector<int> & arr, int n){
    // create stack
    stack<int> st;
    st.push(-1); //for the last element of the array
    // answer array
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int current = arr[i];
        while(st.top() >= current){
            st.pop();
        }
        // if we are out of this loop, the element is small
        ans[i] = st.top();
        st.push(current);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,4,3};
    vector<int> res = nextSmallerElement(arr, arr.size());
    for(int item : res){
        cout<<item<<" ";
    }
    cout<<endl;
}