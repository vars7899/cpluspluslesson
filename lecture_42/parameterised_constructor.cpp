#include <bits/stdc++.h>
using namespace std;

class Hero{
    private:
    bool isAdmin;
    int scope;
    char level;
    int health;

    public:
    string name;

    // ? default constructor
    Hero(){
        cout<<"object is initiated"<<endl;
    }

    // ? parameterised constructor
    Hero(int health){
        this->health = health;
    }

    Hero(string name, int health, char level){
        this->name = name;
        this->health = health;
        this->level = level;
    }

    // getter and setter methods
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }

    // function members
    void printObjectInfo(){
        cout<<"Name --> "<<this->name<<endl;
        cout<<"Level --> "<<this->level<<endl;
        cout<<"Health --> "<<this->health<<endl;
    }

};


int main(){
    Hero h1; // static initialization
    h1.setName("app");
    cout<<h1.getName()<<endl;
    h1.printObjectInfo();

    Hero *h2 = new Hero("pappu", 100, 'A'); // dynamic initialization
    h2->printObjectInfo();

}