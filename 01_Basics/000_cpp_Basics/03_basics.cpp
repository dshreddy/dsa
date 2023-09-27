/*
Members may be declared to be public, which means that they are accessible from outside the class, or private, which means that they are accessible only from within the class.

Member functions may either be defined inside or outside the class body. Most C++ style manuals recommend defining all member functions outside the class

when a member function is defined outside the class body, it is necessary to specify which class it belongs to, which is done by preceding the function name with the scoping specifier class name::member name.

Every class that allocates its own objects using new should:
• Define a destructor to free any allocated objects.
• Define a copy constructor,which allocates its own new members to storage and copies the contents of member variables.
• Define an assignment operator, which deallocates old storage, allocates new storage, and copies all member variables.
*/

#include<iostream>
using namespace std;

class Counter{
    private:
        int count;
    public:
        Counter(){
            count = 0;
        }
        int getCount(){
            return count;
        }
        void increaseBy(int x){
            count += x;
        }
};

class Vect{
    private:
        int *data;
        int size;

    public:
    //constructor
        Vect(int n){
            size = n;
            data = new int[n];
        }

        //copy constructor
        Vect(Vect& a){
            size = a.size;
            data = new int[size];
            for(int i=0; i<size; i++) data[i] = a.data[i];
        }

        //assignment constructor
        Vect& operator=(Vect& a){
            if(this != &a){             //avoid self assignment
                delete [] data;
                size = a.size;
                data = new int[size];
                for(int i=0; i<size; i++) data[i] = a.data[i];
            }
            return *this;
        }

        //destructor
        ~Vect(){
            delete [] data;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Counter ctr;
    ctr.increaseBy(10);
    cout<<ctr.getCount()<<endl;

    Vect v(2);
    Vect v1(1);
}