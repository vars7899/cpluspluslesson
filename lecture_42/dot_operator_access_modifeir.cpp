#include <bits/stdc++.h>
using namespace std;

// ! There are three types of access modifier 
// 1. Private
// 2. Public
// 3. Protected
// ? by default the access modifier within the class is private

// ? Public access --> data members that can be accessed by anyone within the class or outside tha class
// ? Private access members --> data members that can be accessed only within the class
// ? Protected access members -->

// user defined data type --> class
class Avatar{
    // properties
    public:
    string name;
    int health;
    char level;

    private:
    bool admin;

    public:
    void isAdmin(){
        // we can access the admin prop inside the class but no outside the class as it is a private member
        cout<<admin<<endl;
    }
};

int main(){
    // ? We can access the properties of the object using the dot operator(.)
    Avatar angel;
    angel.name = "priya";
    angel.health = 100;
    angel.level = 'F';
    cout<<angel.name<<endl;
    cout<<angel.health<<endl;
    cout<<angel.level<<endl;
}