#include <bits/stdc++.h>
using namespace std;

// @ ULITIY
void printArr(vector<int> a){
    cout<<"[ ";
    for(int item: a){
        cout<<item<<" ";
    }cout<<" ]"<<endl;
}
// @ ULITIY


// ? The logic behind this question is same as any other question for reversing, we reverse the ith element with the n-ith element
// ? there are two ways to solve this question either to take two pointer one that start from 0the index and othe that start from the (n-1)th index and interchanging them.
// ? Or, as used below use only one pointer and define its relation with the other position as (n-i-1)  
void reverseStr(string &str, int start, int n){
    // base case;
    if(start >= n/2) return;
    // recursive relation
    swap(str[start], str[n-start-1]);
    reverseStr(str,start+1,n);
}

// ? The logic is same that check the first index and its equivalent last index (n-i-1) if they are same the reverse of the string will be the same otherwise will be different and hence not a palindrome
bool isPalin(string &str, int start, int n){
    // base case
    if(start >= n/2) return  true;
    // processing
    if(str[start] != str[n-start-1]) return false;
    // recursive call
    return isPalin(str,start+1,n);
}
// ? The logic here is to use the functional recursion to keep on multiplying the number until you reach the time you want number to be multiplied
// ? when reached the times return 1 not 0 as we are doing multiplication, returning 0 at base case will make the answer 0 always 
int getPower(int a, int b){
    long long int response;
    if(b <= 0) return 1;
    response = a * getPower(a,b-1);
    return response;
}

// !important
// ? bubble sort --> using the loops(rounds)
void bubbleSort(vector<int> &nums){
    int n = nums.size();
    for(int i=1;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-i;j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
                break;
        }
    } 
}
void bubbleSort_recursion(vector<int> &nums, int n){
    // base case
    if(n == 1 || n == 0) return;
    for(int i=0; i<n;i++){
        if(nums[i] > nums[i+1]){
            swap(nums[i], nums[i+1]);
        }
    }
    bubbleSort_recursion(nums,n-1);
}
int main(){
    // ! Question 1
    // ! Given a string str return the str reversed
    // ! for example --> 
    // ! input = "abcde" ,output = "edcba"
    // ! input = "dhiman", output = "namidh"
    // string myStr;
    // cin >> myStr;
    // reverseStr(myStr, 0, myStr.size());
    // cout<<myStr;
    // ! Question 2
    // ! check is a given input is palindrome or not
    // ! for example --> 
    // ! 122abc1 | 1cba221 --> not a palindrome
    // ! 156aba651 | 156aba651 --> is a palindrome
    // string myStr;
    // cin >> myStr;
    // isPalin(myStr,0,myStr.size()) ? cout<<myStr<<" is Palindrome"<<endl : cout<<myStr<<" is NOT Palindrome"<<endl;
    // ! Question 3
    // ! given two int input a and b return the a^b
    // ! for example -->
    // ! a = 5, b = 3 output = 125
    // int a, b;
    // cin >> a >> b;
    // cout << getPower(a,b);
    // ! Question 4
    // ! Bubbel sort using the recursion
    vector<int> arr= {3,2,5,6,7,3,5,7,2,1};
    cout<<"Before----------"<<endl;
    printArr(arr);
    bubbleSort(arr);
    cout<<"After----------"<<endl;
    printArr(arr);

}