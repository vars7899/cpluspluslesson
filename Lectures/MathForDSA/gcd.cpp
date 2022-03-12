#include <bits/stdc++.h>
using namespace std;



// Formula for GCD(greatest common divisor)
// gcd(a,b) = gcd(a-b,b)
// gcd(a,b) = gcd(a%b,b)
// GCD and HCF are the same things
int gcd(int a, int b){
    // edge cases
    if(a==0) return b;
    if(b==0) return a;

    while(a != b){
        if(a>b) a = a - b;
        else b = b - a;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"Enter two numbers to find there GCD"<<endl;
    cin>>a>>b;

    int ans = gcd(a,b);
    cout<<"Greatest common factor of "<<a<<" , "<<b<<" is "<<ans<<endl;
}