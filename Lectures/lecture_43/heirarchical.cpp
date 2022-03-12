#include <bits/stdc++.h>
using namespace std;

// ? Example of Hierarchical inheritance
// Book is the parent class for both MathBook and ChemistryBook

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

int main(){
    ChemistryBook c1;
    cout<<c1.getIso()<<endl;
    cout<<c1.getSubject()<<endl;
}