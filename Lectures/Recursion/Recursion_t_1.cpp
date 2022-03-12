#include <bits/stdc++.h>
using namespace std;
#define baseCase 5

void printX(){
int counter = 0;
    if(counter == baseCase){
        return;
    } 
    cout<<counter<<" "<<"X"<<endl;
    counter++;
    printX();
}

int main(){
    printX();
    return 0; 
}