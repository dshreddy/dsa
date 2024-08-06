//polymorphism as the ability of a message to be displayed in more than one form.
//There are 2 types of polymorphism 
// 1) Compile time 2) Run time
// 1) Compile time polymorphism has 2 types 1)Operator overloading 2) Function overloading
// 2) Run time polymorphism -> Virtual functions

/////////////////////////////////// Polymorphism /////////////////////////////////

// #include<bits/stdc++.h>
// using namespace std;

// class poly {     
// public:
//     poly() {}

//     void fun()
//     {
//         cout<<"No arguments\n";
//     }
//     void fun(int x)
//     {
//         cout<<"int argument\n";
//     }
//     void fun(double x)
//     {
//         cout<<"double argument\n";
//     }
// };

// int main()
// {
//     poly p;
//     p.fun();
//     p.fun(1);
//     p.fun(1.2);
// }

/////////////////////////////////// Compile time /////////////////////////////////

// #include<bits/stdc++.h>
// using namespace std;

// // Operator overloading
// class Complex {
// public:
//     // a + ib
//     int a,b;

//     Complex() {}

//     Complex(int real, int imag) {

//         a = real;
//         b = imag;
//     }

//     Complex operator+(Complex &u){

//         Complex res;
//         res.a = a + u.a;
//         res.b = b + u.b;

//         return res;        
//     }

//     void display() {

//         cout<<a<<" + "<<b<<"i"<<endl;
//     }
// };

// int main()
// {
//     Complex u(1,2),v(2,3),w;

//     w = u+v;
//     w.display();
// }

/////////////////////////////////// Run time polymorphism /////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

class base {

public:
    base() {}

    virtual void print() {

        cout<<"base class ki print function\n";
    }

    void display() {

        cout<<"base class ki display function\n";
    }
};

class derived : public base {

public:
    derived() {}

    void print() {

        cout<<"derivied class ki print function\n";
    }

    void display() {

        cout<<"derivied class ki display function\n";
    }
};

int main()
{
    base * baseptr;
    derived d;
    baseptr = &d;

    baseptr->print();
    baseptr->display();
}

