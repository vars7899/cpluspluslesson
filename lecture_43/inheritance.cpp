#include <bits/stdc++.h>
using namespace std;

// ? Parent class
class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }
    int getHeight(){
        return this->height;
    }
    int getWeight(){
        return this->weight;
    }

    void setAge(int age){
        this->age = age;
    }
    void setHeight(int height){
        this->height = height;
    }
    void setWeight(int weight){
        this->weight = weight;
    }
};

// ? child class
class Male: public Human{
    public:
    string color{"Brown"};

    public:
    void attack(){
        cout<<"Attack started"<<endl;
    }
};

int main(){
    Male m1;

    // ? super class access --> public, mode of inheritance --> public, can be accessed
    // ? super class access --> private, mode of inheritance --> public, can be accessed
    // ! CTE --> as the access type of age is private, so it cannot be accessed by the sub class
    // ? super class access --> protected, mode of inheritance --> public, can be accessed

    // Male class has all the properties and methods of its super class human
    m1.setAge(22);
    m1.setHeight(183);
    m1.setWeight(95);

    cout<<m1.getAge()<<endl;
    cout<<m1.getHeight()<<endl;
    cout<<m1.getWeight()<<endl;

    // Male also have its own methods and properties
    cout<<m1.color<<endl;
    m1.attack();
}