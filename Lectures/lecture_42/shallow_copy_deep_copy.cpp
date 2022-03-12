#include <bits/stdc++.h>
using namespace std;

// ? shallow copy and deep copy
// ? shallow copy --> creates a copy of object that access the same memory
// ? deep copy --> create a new memory block

// ! The default copy constructor always create shallow copy not deep copy
class Hero{

    public:
    char *name;
    private:
    int health;
    char level;

    public:
    Hero(){
        name = new char[100];
    }
    // ? copy constructor
    Hero(Hero &input){
        // ! we adding 1 as there is also null(/0) at the end of the char array
        char *n =  new char[strlen(input.name) + 1];
        strcpy(n, input.name);
        
        this->name = n;
        this->health = input.health;
        this->level = input.level;
    }
    void setName(char name[]){
        strcpy(this->name, name);
    }
    void setHealth(int health){
        this->health = health;
    }
    void setLevel(char level){
        this->level = level;
    }
    void info(){
        cout<<"{ "<<endl;
        cout<<"\t name: "<<this->name<<","<<endl;
        cout<<"\t level: "<<this->level<<endl;
        cout<<"\t health: "<<this->health<<","<<endl;
        cout<<"} "<<endl;
    }
};
int main(){
    Hero h1;

    char name[10] = "AAA";

    h1.setName(name);
    h1.setHealth(100);
    h1.setLevel('0');
    h1.info();

    Hero h2(h1);
    h2.info();

    h1.name[0] = 'B';
    // we have changed the first character of the name of object h1 so object h1 name should be BAA now, but it should not change th name of the h2 object, but as it is shallow copy it will refer to the same memory location where the h1 name is stored
    h1.info();
    h2.info();
}