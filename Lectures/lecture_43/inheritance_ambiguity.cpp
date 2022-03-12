#include <bits/stdc++.h>
using namespace std;

class A{
    private:
    string name = "A";

    public:
    void printName(){
        cout<<this->name<<endl;
    }
};

class B{
    private:
    string name = "B";

    public:
    void printName(){
        cout<<this->name<<endl;
    }
};

class C : public A, public B{
    public:
    string name = "C";

    public:
    void printName(){
        cout<<this->name<<endl;
    }
};

int main(){
    C *c1 = new C();
    // to access the printName of A
    c1->A::printName();
    // to access the printName of B
    c1->B::printName();
    // to access the printName of C
    c1->C::printName();
}