#include <bits/stdc++.h>
using namespace std;

void q1(){
    int first = 8; // variable with value 8
    int second = 18; // variable with value 18
    int *ptr = &second; // pointer to variable second
    *ptr = 9; // whereever ptr is pointing change its value to 9 
    // @ print out --> 8 9
    cout<<first<<" "<<second<<endl; 
}
void q2(){
    int first = 6; // variable first with value 6
    int *p = &first; // create pointer p pointing to variable first
    int *q = p; // create pointer q pointing to the value inside p(that will be mem address) so it will be a pointer to the first variable
    (*q)++; // increment the value of whatever q is pointing to which is first
    // this will lead to increase in value of first
    // @ print out --> 7
    cout<<first<<endl; 
}
void q3(){
    int first = 8; // variable first with value of 8
    int *p = &first; // create pointer p pointing to first variable
    //use the value at *p then increment it(post-increment)
    cout<<(*p)++<<" "; //@ output --> 8
    cout<<first<<endl; //@ output --> 9
    //@ output --> 8 9
}
void q4(){
    int *p = 0; //null pointer;
    int first = 110; //variable first with value of 110
    // !this will give segmentation fault
    *p = first; //will give error
    // as we are trying to put 110 in a type of pointer
    cout<<*p<<endl; 
}
void q5(){
    int first = 8; //variable first with value 8
    int second = 11; //variable second with value 11
    int *third = &second; // create pointer third pointing to second variable
    first = *third; //update the value of first to 11
    *third = *third + 2; //update the value of second variable to 13
    cout<<first<<" "<<second<<endl;
    // @ output --> 11 13
}
void q6(){
    float f = 12.5; //variable f of type float and value equal to 12.5
    float p = 21.5; // variable p of type float and value 21.5
    float *ptr = &f; // create pointer ptr that will point to a float variable f
    (*ptr)++; //increment the value of f to 13.5
    *ptr = p; // this will change the value of f to 21.5
    cout<<*ptr<<" "<<f<<" "<<p<<endl;
    // @ output --> 21.5 21.5 21.5
}
void q7(){
    int arr[5]; //array of length 5 
    int *ptr; //wild pointer
    // As the sizeof(arr) will be 5 x size of INT that is 5 x 4 --> gives 20 bytes
    // and ptr is a pointer so it will store a mem address which will be of 8 bytes
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;
    // @ output --> 20 8
}
void q8(){
    int arr[] = {11,21,13,14};
    //      arr[0]      arr[0+1]
    cout<<*(arr)<<" "<<*(arr+1)<<endl;
    // @ output --> 11 21
}
void q9(){
    int arr[6] ={11,12,31}; // array of length 6
    cout<<arr<<" "<<&arr<<endl; // arr will return the memory address of the first element of the array and the &arr will use the address operator to return the memory addres of the first element of the array
    // @ output --> memoryAddressOfarr(0) memoryAddressOfarr(0)
}
void q10(){
    int arr[6] = {11,21,13}; //array of 6 elements
    // ? her arr will return the memory address of the first element of the array and we will do pointer airthemetic on this memory address and increment it by sizeof(INT) --> 4
    cout<<(arr+1)<<endl;
    // @ output --> (memory address of &arr[0] and add 4bytes to that memory address that will actually point to the memory addres of th second element in the array)
}
void q11(){
    int arr[6] = {11,21,31};
    int *p = arr; //pointer pointing to the first element of the array as arr will return a address and it is same as &arr or &arr[0]
    // this p[2] under the hood works like *(arr+2)
    cout<<p[2]<<endl; 
    // @ output --> 31
}
void q12(){
    int arr[]={11,12,13,14,15}; // array initialised
    // *arr points to arr[0] --> 11 and *(arr+3) points to arr[3] --> 14
    cout<<*(arr)<<" "<<*(arr+3)<<endl;
    // @ output --> 11 14
}
void q13(){
    int arr[] ={11,21,31,41};
    // int *ptr = arr++; //this line is saying put the pointer to the first element and then increment the starting of the array from the second element 
    // cout<<*ptr<<endl;
    //! will give an error
}
void q14(){
    char ch ='a';
    char *ptr = &ch;
    ch++; // update a to b
    cout<<*ptr<<endl;
    // @ output --> b

}
void q15(){
    char arr[] = "abcde";
    char *p = &arr[0];
    cout<<p<<endl; //as cout implementation for char is different instead of printing memory address it will print the whole thing until it finds the null(.\) character
    // @ output --> abcde
}
void q16(){
    char arr[] = "abcde";
    char *p = &arr[0];
    p++; //will move the pointer from arr[0] to arr[1]
    cout<<p<<endl; //this will print until it finds the null(.\) character
    // @ output --> bcde
}
// ! imp
void q17(){
    char str[] ="babbar";
    char *p = str;
    cout<<str[0]<<" "<<p[0]<<endl;
    // @ output --> b b
}
void update(int *p){
    *p = (*p) * 2;
}
void q18(){
    int i = 10;
    update(&i); //passing mem address to the update function
    cout<<i<<endl;
    // @ output --> 20
}
void q19(){
    int first = 110; // variable first value 110
    int *p = &first; //pointer pointing to first
    int **q = &p; //pointer pointing to first through p pointer
    int second = (**q)++ + 9; //use post increment
    cout<<first<<" "<<second<<endl;
    // @ output --> 111 119
}
void q20(){
    int first = 100; // variable first value 100
    int *p = &first; //pointer pointing to first
    int **q = &p; //pointer pointing to first through p pointer
    int second = ++(**q); //use pre increment the value of first-->101 and put value of second as 101
    int *r = *q; //pointer that points to first
    ++(*r); //pre increment the value of first-->102
    cout<<first<<" "<<second<<endl;
    // @ output --> 102 101
}
// ! imp
void increment(int **p){
    ++(**p); //the double pointer doesnot matter here it will just update the value of pointer
}
void q21(){
    int num = 110; // variable num with value 110
    int *ptr = &num; //create pointer that points to num
    increment(&ptr);
    cout<<num<<endl;
    // @ output --> 111
}
int main(){
   q1(); 
   q2();
   q3();
//    q4();
   q5();
   q6();
   q7();
   q8();
   q9();
   q10();
   q11();
   q12();
//    q13();
   q14();
   q15();
   q16();
   q17();
   q18();
   q19();
   q20();
   q21();

   return 0;
}