#include <bits/stdc++.h>
using namespace std;

// ! Recursion --> when a function calls itself it is know as recursion
// ! jab ek baddi problem ka solution depend karta hai chotti problem je solution se
// ? there are three part in recursion problem
// ? 1. --> base case
// ? 2. --> processing
// ? 1. --> recursive relation
// ? A recursive function syntax we look like something as below
// ? return_type recur_func(data_type input){
// ? base case

// ? processing

// ? recursive relation
// ? }
// ! the recursion can be divided into 2 types --> tail recursion and head recursion
// ! if the processing is before the recursive relation it is known as tail recursion
// ! if the processing is after the recursive relation it is known as head recursion

int factorail_rec(int n){
    // * if we want to find a factorial of number the bigger number can be broke up into smaller number
    // * 5! = 5 x 4!
    // * 4! = 4 x 3!
    // * 3! = 3 x 2!
    // * 2! = 2 x 1!
    // * 1! = 1 x 0!
    // ? f(n) = n * f(n-1)
    long long int res = 1;
    if(n != 0){
        res = n * factorail_rec(n-1);
    }
    return res;
}
int pow_2(int n){
    long long int res = 1;
    if(n != 0){
        res = 2 * pow_2(n-1);
    }
    return res;
}
void print_num(int n){
    if(n != 0){
        cout<<n<<" ";
        print_num(n-1);
    }
}
int main(){
    int fac_n, pow_n, print_n;
    cin >> fac_n >> pow_n >> print_n;
    cout<<factorail_rec(fac_n)<<endl;
    cout<<pow_2(pow_n)<<endl;
    print_num(print_n);
}