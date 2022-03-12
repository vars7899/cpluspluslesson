#include <bits/stdc++.h>
using namespace std;

// * using loop
// int sum(int N){
//     int sum = 0;
//     for(int i=0;i<=N;i++){
//         sum += i;
//     }
//     return sum;
// }
// * using recursion
// int sum(int start, int N, int &total){
//     // base case
//     if(start > N) return 0;
//     // process
//     total += start;
//     sum(start + 1, N, total);
//     return total;
// }
// * other way using recursion
// * parameterised recursion 
// int sum(int N, int total){
//     if(N < 1){
//         return total;
//     }
//     return sum(N-1, total+N);
// }
// * functional recursion
int sum(int N){
    if(N<1) return 0;
    int total = 0;
    total = N + sum(N-1);
    return total;
}
// * factorial soln using functional recursion
// * time complexity --> O(N)
// * stack complexity --> O(N)
int fact(int N){
    if(N == 1) return 1;
    int res = 1;
    res = N * fact(N-1);
    return res;
}
// * factorial soln using parmeterised recursion
int fact_2(int N, int mult){
    if(N == 1) {
        return mult;
    }
    return fact_2(N-1, mult*N);
}
int main(){
    // ! summation of first N numbers
    int N, start = 1, total = 0, mult = 1;
    cin >> N;
    // cout<<sum(N)<<endl;
    // ! factorial of N
    cout<<fact_2(N, mult)<<endl;
}