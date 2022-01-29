#include <bits/stdc++.h>
using namespace std;

int fibonacciNumber(int number){
    if(number == 0 || number == 1){
        return number;
    }
    int ans = 0;
    // The recursive relation is as follows --> as the next number is fibonacci series is the sum of last tow digits
    ans = fibonacciNumber(number - 1) + fibonacciNumber(number - 2);
    return ans;
}
void sayDigit(int number, string map[]){
    if(number == 0) return;
    int digit = number%10;
    number = number/10;
    sayDigit(number,map);
    cout<<map[digit]<<" ";
}
int main(){
    // find the fibonacci series element
    // using the recursion
    // 0 1 1 2 3 5 8 13 21 - - - - n;
    // what is the 8th fibonacci number? --> 13 
    // int fib_n;
    // cin >> fib_n;
    // cout << fibonacciNumber(fib_n);

    string map[] = {
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight",
        "nine"
    };
    sayDigit(312, map);
}