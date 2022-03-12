#include <bits/stdc++.h>
using namespace std;

// ? problem 1 soln
// * time complexity --> O(N)
// * stack complexity --> O(N)
void printName(int N, int start){
    if(start > N) return;
    cout<<"Vaibhav"<<endl;
    printName(N, start+1);
}
// ? problem 2 soln
// * time complexity --> O(N)
// * stack complexity --> O(N)
void printOneToN(int N, int counter){
    // base condition
    if(counter > N){
        return;
    }
    // processing
    cout<<counter<<endl;
    // recursive relation
    printOneToN(N, counter+1);
}
// ? problem 3 soln
// * time complexity --> O(N)
// * stack complexity --> O(N)
void printNToOne(int N, int counter){
    // base condition
    if(counter > N) return;
    // recursive relation
    printNToOne(N, counter+1);
    // processing
    cout<<counter<<endl;
}
// ? problem 4 soln
void printOneToN_BackTrack(int start, int N){
    // base case
    if(start < 1) return;
    // recursive relation
    printOneToN_BackTrack(start-1, N);
    // processing
    cout<<start<<endl;
}
// ? problem 5 soln
void printNToOne_BackTrack(int start, int N){
    if (start > N) return;
    printNToOne_BackTrack(start+1,N);
    cout<<start<<endl;
}
int main(){
    /*
    // ! problem 1: Write your name using recursion for N times
    int N, start = 1; //* counter to keep track of the number of times to print name
    cin >> N;
    printName(N, start);
    // ! problem 2: Print linearly from 1 to N
    int N, counter2 = 1;
    cin >> N;
    printOneToN(N, counter2);
    // ! problem 3: print linearly from N to 1;
    int N, counter3 = 1;
    cin >> N;
    printNToOne(N, counter3);
    // ! print from 1 to N using recursion and back tracking
    int N;
    cin >>N;
    printOneToN_BackTrack(N,N);
    */
    // ! print from N to 1 using recursion and back tracking
    int N;
    cin >>N;
    printNToOne_BackTrack(1,N);
}