#include <bits/stdc++.h>
using namespace std;

int firstPosition(vector<int> &arr, int n, int k){
    int start = 0;
    int end = n - 1;
    int first = -1;
    while(start <= end){
        int mid = start + (end -start)/2;
        if(arr[mid] == k){
            first = mid;
            end = mid - 1;
        }else if(arr[mid] > k){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return first;
}
int lastPosition(vector<int> &arr, int n, int k){
    int start = 0;
    int end = n - 1;
    int last = -1;
    while(start <= end){
        int mid = start + (end -start)/2;
        if(arr[mid] == k){
            last = mid;
            start = mid + 1;
        }else if(arr[mid] > k){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k){
    pair<int, int> answer ={-1,-1}; 
    answer.first = firstPosition(arr,n,k);
    answer.second = lastPosition(arr,n,k);
    return answer;
}
// ! solution using the recursion approach
int firstPosition_recursion(vector<int> arr, int start, int end, int k){
    // base case 
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(arr[mid] == k){
        int rem = firstPosition_recursion(arr,start,mid-1,k);
        if(rem == -1) return mid;
        else{
            return rem;
        }
    }
    if(arr[mid] > k){
        return firstPosition_recursion(arr, start, mid-1,k);
    }else{
        return firstPosition_recursion(arr, mid+1, end,k);
    }
}
int lastPosition_recursion(vector<int> arr, int start, int end, int k){
    // base case 
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(arr[mid] == k){
        int rem = lastPosition_recursion(arr,mid+1,end,k);
        if(rem == -1) return mid;
        else{
            return rem;
        }
    }
    if(arr[mid] > k){
        return lastPosition_recursion(arr, start, mid -1,k);
    }else{
        return lastPosition_recursion(arr, mid +1, end, k);
    }
}
pair<int, int> firstAndLastPosition_recursion(vector<int> &arr, int n, int k){
    pair<int, int> answer ={-1,-1}; 
    answer.first = firstPosition_recursion(arr,0,n-1,k);
    answer.second = lastPosition_recursion(arr,0,n-1,k);
    return answer;
}


int main(){
    vector<int> a = {0,0,1,1,2,2,2,3};
    pair<int,int> response = firstAndLastPosition_recursion(a, 8, 2);
    cout<<response.first<<" "<<response.second<<endl;
    cout<<"Total number of occurrence = "<<response.second-response.first+1<<endl;
}