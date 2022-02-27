#include <bits/stdc++.h>
using namespace std;

// class Student
class Student{
    // private data members can only be accessed within the class and not by any other class
    private:
    string name;
    int rollNo;
    int age;

    public:
    // getter methods to access the information of private class members
    // get student name
    string getName(){
        return this->name;
    }
    // get student roll number
    int getRollNo(){
        return this->rollNo;
    }
    // get studen age
    int getAge(){
        return this->age;
    }
    // setter methods to manipulate the values of private data members
    // set student name
    void setName(string name){
        this->name = name;
    }
    // set student roll number
    void setRollNo(int rollNo){
        this->rollNo = rollNo;
    }
    // set student age
    void setAge(int age){
        this->age = age;
    }
};

int main(){
    Student *s1 = new Student();

    string name = "Anuj";
    s1->setName(name);
    s1->setRollNo(31);
    s1->setAge(22);

    cout<<"Name: "<<s1->getName()<<endl;
    cout<<"Roll No: "<<s1->getRollNo()<<endl;
    cout<<"Age: "<<s1->getAge()<<endl;
}