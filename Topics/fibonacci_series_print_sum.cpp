#include <bits/stdc++.h>
using namespace std;

int sum_fib(int start , int &sum){
    // ! if n == 0 --> return 0
    if(start <= 1){
        return 0;
    }
    if(start == 2){
        return 1;
    }else{
        int first = 0;
        int second = 1;
        int next = 0;
        int count = 2;
        while(count < start){
            next = first + second;
            first = second;
            second = next;
            count++;
            sum += next;
        }
    }
    return sum;
}

int main(){
    vector<int> fib_ser = {0,1};
    int u_input, sum = 1;
    cin>>u_input;
    cout<<sum_fib(u_input, sum)<<endl;
}