#include <bits/stdc++.h>
using namespace std;

// Approach #1 --> BAD approach(each stack be the size of n/2) not optimal use of memory
// Approach #2 --> one stack from array start and other from array end.
class TwoStack{
    private:
    int* arr;
    int top1;
    int top2;
    int size;

    public:
    // constructor
    TwoStack(int s){
        // create a new array of s size
        arr = new int[s];
        this->size = s;
        this->top1 = -1;
        this->top2 = this->size;
    }
    // push1(NUM) - Push ‘NUM’ into stack1.
    // insertion for the first array will be from left to right
    void push1(int num){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
            return;
            cout<<"Stack OverFlowed"<<endl;
            return;
        }
        cout<<"Stack OverFlowed"<<endl;
        return;
    }
    // push2(NUM) - Push ‘NUM’ into stack2.
    void push2(int num){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
            return;
        }
        cout<<"Stack OverFlowed"<<endl;
        return;
    }
    // pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
    int pop1(){
        if(top1 >= 0 && top1 < this->size){
            int response = arr[top1];
            top1--;
            return response;
        }
        cout<<"Stack UnderFlowed"<<endl;
        return -1;
    }
    // pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1 
    int pop2(){
        if(top2 < this->size && top2 >= 0){
            int response = arr[top2];
            top2++;
            return response;
        }
        cout<<"Stack UnderFLowed"<<endl;
        return -1;
    }
};


int main(){
    TwoStack* t = new TwoStack(5);
    t->push1(1);
    t->push2(2);
    t->push1(1);
    t->push1(1);
    t->push1(1);
}