#include <bits/stdc++.h>
using namespace std;

class Phone{
    public:
    char *brand;

    private:
    int ram;
    int storage;
    int battery;

    // parameterised constructor
    public:
    Phone(char name[], int ram, int storage, int battery){
        this->brand = name;
        this->ram = ram;
        this->storage = storage;
        this->battery = battery;
    }
    // copy constructor
    Phone(Phone &ph){
        // deep-copy
        char *b = new char[strlen(ph.brand)+1];
        strcpy(b, ph.brand);
        this->brand = b;
        this->ram = ph.ram;
        this->storage = ph.storage;
        this->battery = ph.battery;
    }
    void info(){
        cout<<"{"<<endl;
        cout<<"\t Brand: "<<this->brand<<endl;
        cout<<"\t RAM: "<<this->ram<<endl;
        cout<<"\t Storage: "<<this->storage<<endl;
        cout<<"\t Battery: "<<this->battery<<endl;
        cout<<"}"<<endl;
    }
    void setStorage(int storage){
        this->storage = storage;
    }
};

int main(){
    char name[20] = "Realme";
    Phone p1(name, 8, 1024, 5500);
    p1.info();
    Phone p2(p1);
    p2.setStorage(2048);
    p2.info();
    p1.info();
    char name2[20] = "Samsung";
    Phone p3(name2, 16, 3072, 4000);
    p3.info();
    // ? The following is the use of copy assignment operator, it is going to copy all the property of the object on the right of the operator to the object on the left of the operator
    // p1.brand = p3.brand
    // p1.ram = p3.ram
    // p1.storage = p3.storage
    // p1.battery = p3.battery
    p1 = p3;
    p1.info();
}