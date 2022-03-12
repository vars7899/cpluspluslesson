#include <bits/stdc++.h>
using namespace std;

class flower{
    public:
    string color = "#fff";
    private:
    int height;
    double width;

    public: 
    int getHeight(){
        return height;
    }

    void setHeight(int h){
        height = h;
    }
};

int main(){
    // static allocation of object
    flower f1;
    // to print the color of f1, we will use the dot operator(.)
    cout<<f1.color<<endl;
    f1.setHeight(10);
    cout<<f1.getHeight()<<endl;
    // dynamic allocation of object
    flower *f = new flower;
    // to access the properties and the method we can use (*f) using dereference operator and dot operator or -> 
    cout<<(*f).color<<endl;
    cout<<f->color<<endl;
    f->setHeight(100);
    cout<<f->getHeight()<<endl;
}