#include <bits/stdc++.h>
using namespace std;

class Hero{
    private:
    string name = "sample";
    bool isAdmin = false;
    int health = 0;
    char level = '0';

    // parameterised constructor
    public:
    Hero(string name, char level, int health){
        this->name = name;
        this->level = level;
        this->health = health;
    }
    // copy constructor
    // We have to use pass by reference when using the copy constructor as if we pass by value its gonna create a new copy and in order to create new copy it is going to call the copy constructor which is going to ask for inputHero which is pass by value so its gonna create a new copy by calling the copy constructor, So there is going to be a infinite loop, that's why we use the pass by reference
    // when we create our own copy constructor the compiler is not going to create a default copy constructor
    Hero(Hero &inputHero){
        this->name = inputHero.name;
        this->level = inputHero.level;
        this->health = inputHero.health;
    }
    void printInfo(){
        cout<<"--- --- --- --- --- --- --- --- --- "<<endl;
        cout<<this->name<<" "<<this->level<<" "<<this->health<<endl;
        cout<<"--- --- --- --- --- --- --- --- --- "<<endl;
    }
};

int main(){
    Hero *batman = new Hero("batman", 'A', 100);
    // ! what if i want to create another Hero object with same properties as batman
    // 1. I can create another object and pass the same argument as passed in the batman object
    Hero *b1 = new Hero("batman", 'A', 100);
    // 2. We can use the COPY CONSTRUCTOR, by default the complier creates a copy constructor just like default constructor but we can also write our own copy constructo
    Hero b2(*batman); //static 
    b2.printInfo();
    Hero *b3 = new Hero(*batman); //dynamic
    b3->printInfo();

}