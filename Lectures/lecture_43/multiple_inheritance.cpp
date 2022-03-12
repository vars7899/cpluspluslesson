#include <bits/stdc++.h>
using namespace std;

class Car{
    public:
    int milage;
    string numOfTyres;
    string fuelType;

    public:
    void honk(){
        cout<<"Honking!!!!!!!"<<endl;
    }
    int accelrate(int currentSpeed, int acc){
        return (currentSpeed+acc);
    }
};

class Engine{
    public:
    int numOfCylinders;
    int horsepower;
    int maxRpm;
};

class Gearbox{
    public:
    int numOfGears;
    bool automatic;
    bool manual;
};

class Gwagon: public Car , public Engine , public Gearbox{
    private:
    string brand = "Mercedes";

    public:
    void getBrand(){
        cout<<this->brand<<endl;
    }
};

int main(){
    Gwagon g1;
    cout<<g1.automatic<<endl;
}