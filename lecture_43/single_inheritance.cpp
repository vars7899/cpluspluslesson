#include <bits/stdc++.h>
using namespace std;

// ? This is an example of single inheritance
class Animal{
    public:
    int weight;
    int age;

    public:
    void speak(string speech){
        cout<<"Type of speech: "<<speech<<endl;
    }
};

class Dog : public Animal{
    public:
    string breed;
};

int main(){
    Dog *d1 = new Dog();
    d1->speak("Bark");
}