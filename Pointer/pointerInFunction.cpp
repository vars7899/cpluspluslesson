#include <bits/stdc++.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}
void update(int *p){
    *p = 800;
}
int getSum(int *arr, int n){ // @ we can write arr[] or *arr is same
    int res = 0;
    int index = 0;
    while(index < n){
        res += *(arr + index++);
    }
    return res;
}
int main(){
    int val = 80;
    int *ptr = &val;
    print(ptr); // @ pass the memory location without dereference operator 
    update(ptr);
    print(ptr);
    int arr[7] = {1,1,1,1,1,1,1};
    cout<<getSum(arr,7)<<endl;
    // ? the benefit here is we can send partial array
    cout<<getSum(arr+2,5)<<endl; 
}