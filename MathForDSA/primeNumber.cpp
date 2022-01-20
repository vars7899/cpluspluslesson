#include <bits/stdc++.h>
using namespace std;

// function to find if a number is prime or composite
// time complexity --> O(k-2), where k is the given input
// space complexity --> O(1)
bool isPrime(int k){
    //edge case
    if(k < 2) {
        // cout<<k<<" is neither prime nor composite"<<endl;
        // exit(EXIT_FAILURE);
        return false;
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

// leetcode --> 204 count primes
// return the number of prime numbers that are strictly less than n.
// strictly less than n so we will check all the number less than n-1;
// time complexity --> O((n-2)*(n-2)), where n is the given input
// space complexity --> O(1)
// this solution will give TLE

// int countPrimes(int n){
//     int index=2;
//     int counter=0;
//     while(index<n){
//         if(isPrime(index)){
//             counter++;
//         }
//         index++;
//     }
//     return counter;
// }

// optimal solution
// using --> sieve of eratosthenes
// time complexity --> O(n*log(log n)) n is the input
// space complexity --> O(n+1)
int countPrimes(int n){
    int count = 0;
    // we have taken n+1 as we want index from 0 to n-1
    // if n = 5; vector will have following index
    // 0 1 2 3 4 5
    vector<bool> primeList(n+1,true);
    // 0 and 1 are not prime
    primeList[0]=false;
    primeList[1]=false;
    for(int i=2;i<n;i++){
        if(primeList[i]){
            count++;
            //now un prime all the numbers that comes in its table
            // loop condition
            // we will start from 2nd row of table
            // keep incrementing by adding j to i
            // to get next number in the table
            for(int j=i*2;j<n;j=j+i){
                primeList[j] = false;
            }
        }
    }
    return count;
}

int main(){
    // basic function to check if a number is prime or not
    isPrime(1)?cout<<"Prime"<<endl:cout<<"NOT Prime"<<endl;
    cout<<countPrimes(5000000);


    return 1;
}