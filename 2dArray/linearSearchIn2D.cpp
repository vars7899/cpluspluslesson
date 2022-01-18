#include <bits/stdc++.h>
using namespace std;
void input(int (*arr)[3]){
    for(int i=0;i<4;i<i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
}
void output(int (*arr)[3]){
    for(int i=0;i<4;i<i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
pair<int,int> LS(int (*arr)[3], int target){
    pair<int,int> p = {0,0};
    for(int i=0;i<4;i<i++){
        for(int j=0;j<3;j++){
            if(arr[i][j] == target){
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    return p;
}
int main(){
    int arr[4][3]; //arr with 4 row 3 col
    int target;
    input(arr);
    output(arr);
    cout<<"Enter targer in search"<<endl;
    cin>>target;
    int row = LS(arr,target).first;
    int col = LS(arr,target).second;
    cout<<row<<" "<<col;
}