#include <bits/stdc++.h>
using namespace std;

class Animal{
    public:
    int height;
    int weight;
    int age;

    public:
    void info(){
        cout<<this->weight<<" "<<this->height<<" "<<this->age<<endl;
    }
};
class Labrador : public Animal{
    public:
    string breed;

    public:
    void bark(){
        cout<<"Barking"<<endl;
    }
};
class Black_labrador : public Labrador{
    private:
    string color{"black"};

    public:
    void myColor(){
        cout<<"My color is "<<this->color<<endl;
    }
};
int main(){

}