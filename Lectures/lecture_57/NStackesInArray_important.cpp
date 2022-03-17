#include <bits/stdc++.h>
using namespace std;

class KStack{
    int* arr; // array for all the stacks
    int* top; // array to keep track of the top element of the stack
    int* next; // array to keep track of the next element in the stack
    int free; // variable to know which is the availble spot in the array

    int n; // size of the array for all the stacks
    int sn; // number of stacks to be created in the array
    public:
    KStack(int n, int sn){
        this->n = n;
        this->sn = sn;
        // initialise free to 0
        free = 0;
        // create the array for stack(dynamically)
        arr = new int[this->n];
        // initialize array for top
        top = new int[this->sn];
        // initialize array for next
        next = new int[this->n];

        // initially all the stacks will be empty, so there top value should be equal to -1(showing that they do not have any value in them)
        // you can use the loop or the memset
        memset(top, -1, sizeof(top)+4);
        // for(int i=0; i<this->sn; i++){
        //     top[i] = -1;
        // }
        // initailise next array
        for(int i=0; i<this->n; i++){
            next[i] = i+1;
        }
        // set the last next index to -1
        next[this->n - 1] = -1;
    }


    // push function
    // parameters --> element to be inserted and stack number in which element to insert
    bool push(int data, int stackNumber){
        // ! before pushing elements check for overflow in the array
        // ! on the last index of next we have put -1, just to show the array is out of space
        if(free == -1){
            cout<<"Stack overflowed"<<endl;
            return false;
        }

        // get the index of the free spot available in the array
        int index = free;

        // update the free
        free = next[index];

        // insert the value given on the index
        arr[index] = data;

        // update the next, as now new element exist in the array
        next[index] = top[stackNumber-1];

        // update the top value
        top[stackNumber-1] = index;

        // successfully pushed element
        return true;
    }

    // pop function
    // parameters --> stack number from which you want to pop element
    int pop(int stackNumber){
        // ! Before poping check if the stack has elements in it, if it does have element
        // ! its top value will not be -1
        if(top[stackNumber-1] == -1){
            cout<<"Stack Underflowed"<<endl;
            return -1;
        }

        // get the top element to be poped from the stack
        int index = top[stackNumber-1];

        // update the top value
        top[stackNumber-1] = next[index];

        // update the next array 
        next[index] = free;

        // update free spot variable 
        free = index;

        // successfully poped the element
        return arr[index];
    }
    void info(){
        cout<<"Array --> ";
        for(int i=0; i<this->n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Top --> ";
        for(int i=0; i<this->sn; i++){
            cout<<top[i]<<" ";
        }
        cout<<endl;
        cout<<"Next --> ";
        for(int i=0; i<this->n; i++){
            cout<<next[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    KStack* ns = new KStack(9, 3);
    ns->info();
    ns->push(10,1);
    ns->push(20,1);
    ns->push(30,2);
    ns->push(30,2);
    ns->push(30,2);
    ns->push(30,2);
    ns->push(30,2);
    ns->info();
    ns->pop(2);
    ns->info();
    ns->pop(1);
    ns->info();
    ns->push(50,3);
    ns->info();
}