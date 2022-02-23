#include <bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int health;
    bool admin = false;

    public:
    char level;
    // getter method --> get the health
    int getHealth(){
        return health;
    }
    // getter method --> get the level 
    int getLevel(){
        return level;
    }
    // setter method --> reset the health
    void resetHealth(){
        health = 100;
    }
    // setter method --> set the level
    void resetLevel(){
        level = '0';
    }
    // setter method --> set the health
    void setHealth(int h){
        health = h;
    }
    // setter method --> set the level
    void setLevel(char ch){
        level = ch;
    }
};

int main(){
    Hero shakti;
    // ? I cannot acces the health property directly but i can use the getter and setter method to access and modify the value of health
    shakti.setHealth(20); // setter method
    cout<<shakti.getHealth()<<endl; // getter method
    shakti.resetHealth();
    cout<<shakti.getHealth()<<endl;
}