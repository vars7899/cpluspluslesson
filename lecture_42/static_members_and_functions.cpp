#include <bits/stdc++.h>
using namespace std;

// ! :: --> is known as scope resolution operator

// ? static function have the following properties
// 1. can be accessed directly without initialising an object
// 2. this keyword is not availble, as this keyword is pointer to current object but in static no object is involved
// 3. static functions can only access static members
class Hero{
    private:
    char *name;
    int health;
    char level;

    // constructor
    public:
    static int timeToComplete; // static member belongs to class not to object
    Hero(){
        name = new char[100];
    }
    // parameterised constructor
    Hero(char name[], int health, char level){
        this->name = name;
        this->health = health;
        this->level = level;
    }
    // copy constructor
    Hero(Hero &h){
        this->name = h.name;
        this->health = health;
        this->level = level;
    }
    // function member
    void info(){
        cout<<"{"<<endl;
        cout<<"\t Name: "<<this->name<<endl;
        cout<<"\t Level: "<<this->level<<endl;
        cout<<"\t Health: "<<this->health<<endl;
        cout<<"}"<<endl;
    }
    static int time(){
        return timeToComplete;
    }

    // destructor
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};

// intializing static member
// The following is the syntax used to initialise the static member
// dataTypeOfProperty className :: propertyName = value
int Hero::timeToComplete = 2020;

int main(){
    // we can access the static class without initialising the class
    cout<<Hero::timeToComplete<<endl;
    // initiate an object
    Hero h;
    cout<<h.timeToComplete<<endl; // bad practice as static member are for class not for object 
    Hero h2;
    
    h2.timeToComplete = 2022;
    cout<<h2.timeToComplete<<endl;

    cout<<Hero::timeToComplete<<endl;
    cout<<Hero::time()<<endl;
}