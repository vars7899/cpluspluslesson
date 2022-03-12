#include <bits/stdc++.h>
using namespace std;
// ? structure padding is the concept of adding extra bytes to make reading easier for compiler, extra bytes added are known as padding 
// ? Size of the class --> it is the sum of all the non-static data members and padding
// ? Amount of padding --> it is compiler dependent and is greedy, it takes the size of biggest data member and add amount the padding accordingly
// ? why padding is added --> as computer read memory locations efficiently of 1 word size which is 4 bytes in most computer
class Box{
    private:
    int height; // sizeof(int) --> 4 bytes
    int width; // sizeof(int) --> 4 bytes
    int length; // sizeof(int) --> 4 bytes
    public:
    char name[10]; // sizeof(char) --> 1 byte x 10 --> 10 bytes
    static int life; // static member size is not added to the class
    // total bytes --> 22 bytes
    // but we see we have 24 bytes 
    // as the compiler add 2 bytes of padding
};

class Plate{
    public: 
    static int life; // not added as static
    char name[10]; // 10 x 1 byte
    private:
    double diameter; // 8 bytes
    int height; // 4 bytes
    // total --> 22
    // actual --> 32    
};
// ? How to avaoid structure padding
// ? --> by putting the higher dat type at the top and small at the bottom
class Plate2{
    public: 
    double diameter; // 8 bytes
    static int life; // not added as static
    private:
    int height; // 4 bytes
    char name[10]; // 10 x 1 byte
    // total --> 22
    // actual --> 32    
};
int main(){
    Box b1;
    cout<<sizeof(b1)<<endl;
    Plate p1;
    Plate2 p2;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
}