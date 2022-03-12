#include <bits/stdc++.h>
using namespace std;

void print_fib_series(int n){
    long long int first_number = 0;
    long long int second_number = 1;
    int count = 0;
    long long int next_number = 0;
    if(n == 0 || n == 1){
        cout<<"0";
        return;
    }
    if(n >= 1){
        cout<<"0 1 ";
    }
    while(count < n-2){
        next_number = first_number + second_number;
        first_number = second_number;
        second_number = next_number;
        cout<<next_number<<" ";
        count++;
    }

}

int main(){
    int u_input;
    cin >> u_input;
    // Q1 --> write the fibonacci series up to the given user input(u_input)
    print_fib_series(u_input);
}