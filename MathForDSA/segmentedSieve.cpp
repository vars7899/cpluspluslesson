#include <bits/stdc++.h>
using namespace std;

// void print(vector<int> arr){
//     int counter = 0;
//     for(int i:arr){
//         cout<<i<<" ";
//     }
// }

void print(vector<bool> arr){
    int counter = 0;
    for(int i;i<arr.size();i++){
        if(arr[i] == true){
            counter++;
        }
    }
    cout<<counter;
}

void sieve(vector<int> &prime,int high){
    long long n = floor(sqrt(high));
    vector<bool> primeList(n,true);
    primeList[0] = false;
    primeList[1] = false;

    for(long long i=2;i<=n;i++){
        if(primeList[i]){
            prime.push_back(i);
            for(long long j=j*j;j<=n;j=j+i){
                primeList[j] = false;
            }
        }
    }
}

int main(){
    // find all the prime numbers between range [low,high] inclusive
    // given 0 <= low,high <= 10^9
    int low,high;
    cin>>low>>high;

    vector<int> prime;
    sieve(prime,high);

    vector<bool> isPrime(high-low+1,true);
    for(int i=0;i<prime.size();i++){
        long long p = prime[i];
        long long sm = (low/p)*p;
        if(sm<low){
            sm = sm + p;
        }
        for(long long mult = sm;mult<=high;mult = mult + p){
            // here it is mult-low as we have made an array for range
            //it is not starting at 0, instead at 0 we have the low and max index is high
            isPrime[mult-low] = false;
        }
        if(sm==p){
            isPrime[sm-low] = true;
        }
    }
    print(isPrime);
}