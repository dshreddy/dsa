//The capability of a class to derive properties and characteristics from another class is called Inheritance.

/////////////////////////////////// Single inheritance /////////////////////////////////

// #include<bits/stdc++.h>
// using namespace std;

// class A{
// public:

//     A() {}

//     void funcA() {

//         cout<<"..A..\n";
//     }
// };

// class B : public A{
// public:

//     B() {}
// };

// int main()
// {
//     B b;
//     b.funcA();
// }

/////////////////////////////////// Multiple inheritance /////////////////////////////////

#include<bits/stdc++.h>
using namespace std;

class A{
public:

    A() {}

    void funcA() {

        cout<<"..A..\n";
    }
};

class B{
public:

    B() {}

    void funcB() {

        cout<<"..B..\n";
    }
};

class C : public A, public B{
public:

    C() {}
};

int main()
{
    C c;
    c.funcA();
    c.funcB();
}

//There are other types of inheritance called as multilevel, hybrid, hierarchal