#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerIndex(vector<int> arr, int n){
    // create stack to keep track of smallest
    stack<int> st;
    st.push(-1);

    // create ans vector
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int current = arr[i];

        while(st.top() != -1 && arr[st.top()] >= current){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerIndex(vector<int> arr, int n){
    // create stack to keep track of smallest
    stack<int> st;
    st.push(-1);
    // create ans vector
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int current = arr[i];
        while(st.top() != -1 && arr[st.top()] >= current){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    
    return ans;
}

int largestArea(vector<int> heights){
    // store the size of the arr heights
    int size = heights.size();

    vector<int> next(size);
    next = nextSmallerIndex(heights, size);

    vector<int> prev(size);
    prev = prevSmallerIndex(heights, size);

    int area = INT_MIN;

    for(int i=0; i<size; i++){
        int length = heights[i];

        if(next[i] == -1){
            next[i] = size;
        }

        int breath = next[i] - prev[i] - 1;

        int newArea = length * breath;
        area = max(area, newArea);
    }

    return area;
}

int main(){
    vector<int> arr = {2,2,2,2};
    cout<<largestArea(arr)<<endl;
}