#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

class Student{
//Can access only inside the class
private:
    bool gender;

//Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
protected:

//Can access from outside class
public:
    //Attributes
    string name;
    int age;

    //Methods
    Student() {} //default constructor

    //parameterised constructor
    Student(string n, int a, bool g) {

        name = n;
        age = a;
        gender = g;
    } 

    //copy constructor
    Student(Student &a) {

        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    //Destructor
    ~Student() {}

    //setter & getter are used to access private elements of a class from outside the class
    void setGender(bool g) {

        gender = g;
    }
    bool getGender() {

        return gender;
    }

    //operator overloading
    bool operator==(Student & a) {

        return (name==a.name && age ==a.age && gender==a.gender);
    }
    //function overloading
    int area(int r) {

        return 3.14*r*r;
    }
    int area(int l, int b) {

        return l*b;
    }
};

signed main()
{
    Student a("Sai",20,true);
}