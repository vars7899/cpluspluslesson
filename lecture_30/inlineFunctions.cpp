#include <bits/stdc++.h>
using namespace std;

// ? In order to free up more memory we use inline functions
// ? An inline function is any function that consist of only one statement
// ! sometime some complier also take two or three statement function as a inline functions
// ? The following is an example 
inline int getMax(int &first, int &second){
    return (first > second) ? first : second;
} 
// ? to declare a function as a inline function simply use the inline keyword before the type it will return.
int main(){
    int first, second;
    char res = 'n';
    do{
        cin>>first>>second;
        cout<<getMax(first,second)<<endl;
        cout<<"Would you like to compare another(Y/N) : ";
        cin>>res;
    }while(res == 'Y' || res == 'y');
}