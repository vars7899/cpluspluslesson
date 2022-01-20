#include <bits/stdc++.h>
using namespace std;

bool isPrime(int k){
    if(k < 2) {
        cout<<k<<" is neither prime nor composite"<<endl;
        exit(EXIT_FAILURE);
    }
    int counter = k - 1;
    while(counter!=1){
        if(k%counter == 0){
            return false;
        }
        counter--;

    }
    return true;
}


int main(){
    // basic function to check if a number is prime or not
    isPrime(1)?cout<<"Prime"<<endl:cout<<"NOT Prime"<<endl;



    return 1;
}