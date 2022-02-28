#include <bits/stdc++.h>
using namespace std;

// ? Example of Hybrid inheritance
// Here in this example we are using more than one type of inheritance, we are using hierarchical and multiple inheritance.

class Book{
    protected:
    int numOfPages;
    string publisher;
    int iso;

    public:
    int getIso(){
        return this->iso;
    }
};

class MathBook : public Book{
    private:
    string subject = "Math";

    public:
    string getSubject(){
        return this->subject;
    }

    void setPages(int numOfPages){
        this->numOfPages = numOfPages;
    }
};

class ChemistryBook : public Book{
    private:
    string subject = "Chemistry";

    public:
    string getSubject(){
        return this->subject;
    }

    void setPublisher(string publisher){
        this->publisher = publisher;
    }
};

class LabBook : public MathBook, public ChemistryBook{
    public:
    char section;
};

int main(){

}