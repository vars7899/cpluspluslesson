#include <bits/stdc++.h>
using namespace std;

class Hero{
    private:
    char *name;
    int health;
    char level;

    // constructor
    public:
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
    // destructor
    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};