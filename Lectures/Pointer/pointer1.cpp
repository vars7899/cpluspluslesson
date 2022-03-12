#include <bits/stdc++.h>
using namespace std;

// more INFO on
// https://www.codingninjas.com/codestudio/guided-paths/pointers/

// why I am getting the value of the variable even though when i am not using the dereference operator in front of the pointer only in the case of char
// ans --> it is how the memory stores the char in memory

int main(){
    // decalaring and intialising a variable
    int num = 10;
    // the above line of code assign a memory location
    // in the memory and map it to the name num in the
    // symbol table
    cout<<"Value of num is: "<<num<<endl;
    // when we actually call the num, the complier will
    // in the symbol table for the name num and check
    // the maping of the name with memory location
    // and return whatever is stored at that memory
    // location(which is 10 here)
    cout<<"variable num is stored at: "<<&num<<endl;
    // & is know as address of operator
    // & is used to get the memory location of any variable
    // memory location is represented in hexadecimal notation 

    // POINTERS -----------------------------------------------
    // def --> variables to store the memory location of another variable are known as pointers

    // pointers are used to store these location of memory
    // like &num value (sum hexadecimal value --> 0x9ffe3ff7ec)
    int *my_pointer = &num;
    // the above line represents that we are creating a pointer
    // named as my_pointer that will point to a int data type
    // that will store the memory location of the num variable

    // Question --> create a pointer for a character variable
    // 1. declaring a character variable
    char ex_char = 'q';
    // we have declared a variable of type character whose name
    // in the symbol table is ex_char which is storing a value 
    // 'q'(ASCII value)
    
    // 2. create a pointer variable and the type of pointer variable
    // should be same as the variable data type it is pointing to
    // which is char here
    char *ex_char_pointer = &ex_char;
    // we have created a pointer named as ex_char_pointer and we
    // know it is a pointer as before the name of pointer we have
    // put *, then we have passed the memory location of our variable

    // So, in a nutshell pointer ex_char_pointer will point to ex_char
    // to get the value of ex_char from pointer we will use the
    // dereference operator (*) which is same symbol used when we 
    // actually create a pointer
    (*ex_char_pointer == ex_char) ? cout<<"same"<<endl : cout<<"not same"<<endl;

    // using and not using dereference operator when accessing the pointer 
    cout<<"Address of my_pointer : "<<my_pointer<<endl;
    cout<<"Value of num : "<<*my_pointer<<endl;

    // -----------------------------------------------------------
    // creating a pointer for double
    double ex_d = 7.899;
    double *ex_p = &ex_d;
    cout<<"\n------------------------------------------"<<endl;
    cout<<"Value of ex_d variable : "<<ex_d<<endl;
    cout<<"Memory location of ex_d variable : "<<&ex_d<<endl;
    cout<<"value of ex_d variable using pointer : "<<*ex_p<<endl;
    cout<<"Value of ex_p pointer : "<<ex_p<<endl;
    cout<<"memory location of ex_p pointer : "<<&ex_p<<endl;
    cout<<"------------------------------------------\n"<<endl;
    // size of pointer will always be 8byte/4bytes(depends on compiler 
    // how much space it takes to store the address), it doesnot depend on the 
    // type of data it is pointing to as it is always going to save the
    // memory address which is of 8 bytes 

    // --------------- BAD PRACTICE -------------------
    // int *ptr; never do this
    // here we have created a pointer which will be pointing to a int
    // but we did not initiated it with any value so, the compiler will
    // give this pointer a garbage value, by chance if you modified it
    // it can change the value of some other program or something else
    // ------------------------------------------------

    // modifying value using pointer
    int val = 1010;
    int dummy = val;
    dummy++;
    cout<<val<<endl;
    // will this change the value of variable val the answer is no
    // as we created a integer val that will point to the memory location
    // in the symbol table and gives its value
    // here we created a copy of the value and pasted in the dummy, we
    // have not passed the memory address of val so, if we modify the
    // dummy value it will not change the actual value of val
    int *val_ptr = &val;
    (*val_ptr)++;
    cout<<val<<endl;
    // the above code will change the value of val, as the pointer is 
    // pointing to the address that hey complier increment the value
    // of the variable that is stored at this location.

    // ---------------COPYING A POINTER--------------------------
    int x = 23423;
    int *ptr_1 = &x;
    int *ptr_2 = ptr_1;
    // we simply pass the value(memory location) that is stored in the
    // ptr_1 to the ptr_2.
    cout<<x<<" - "<<*ptr_1<<" - "<<*ptr_2<<endl;
    cout<<&x<<" - "<<ptr_1<<" - "<<ptr_2<<endl;
    // ----------------------------------------------------------

    // ------------- pointer airthemetic ------> important
    // what is the difference between
    // ptr = ptr + 1 and *ptr = *ptr + 1 , assume ptr is some pointer
    int ghoda = 0;
    int *ghoda_ptr = &ghoda;
    cout<<"before : "<<ghoda<<endl;
    *ghoda_ptr = *ghoda_ptr + 1;
    cout<<"after  : "<<ghoda<<endl;
    // when i do ptr = ptr + 1;
    cout<<"before value : "<<ghoda<<endl;
    cout<<"before mem add : "<<ghoda_ptr<<endl;
    ghoda_ptr = ghoda_ptr + 1;
    cout<<"after value : "<<ghoda<<endl;
    cout<<"after mem add : "<<ghoda_ptr<<endl;
    // it doesnot increment the value of ghoda to 2
    // instead it has moved the pointer to next int(or whatever is 
    // the data type of pointer)
    // if the pointer was at 0xe7eb1ff904 it will move to 0xe7eb1ff908
    // not to 0xe7eb1ff905 as int takes 4 bytes.

    return 0;
}