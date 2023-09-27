#include <bits/stdc++.h>
using namespace std;

// A basic implementation of a dynamic array
class vec
{
private:

    int capacity = 2;      // space allocated for the data structure
    int length = 0;        // number of elements in the data structure
    int *arr = new int[2]; // initialising the ds

public:

    // default constructor
    vec() {}

    // constructor to initialize an array of size = size with each element = num
    vec(int size, int num)
    {
        if(size >= 0) {

            capacity = size;
            length = size;
            arr = new int[capacity];
            for (int i = 0; i < size; i++)
                arr[i] = num;
        }
        else cout<<"Negtaive size allocation is not possible\n";
    }

    //A function to double the size of the array when the array is full & we need to add more elements
    void resize()
    {

        capacity = 2 * capacity;
        int *new_arr = new int[capacity];
        for (int i = 0; i < capacity / 2; i++)
            new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }

    //A function to push elements into DS at end
    void push_back(int num)
    {

        if (length == capacity)
            resize();
        arr[length] = num;
        length++;
    }

    //A function to pop elemets from end of DS
    void pop_back()
    {

        if (length > 0)
        {
            arr[length - 1] = INT_MIN;
            length--;
        }
        else  cout<<"-404 No elements to pop\n";
    }

    //A function that allows similar access to elements in DS like Array
    int operator[](int i)
    {

        if (i>=0 && i < length)
            return arr[i];
        cout<<"-404 Bad Acesss : Out of Bounds\n";
        return INT_MIN;
    }

    void insert(int i, int num) {

        if(i>=0 && i<length) arr[i] = num;
        else cout<<"-404 Bad Acesss : Out of Bounds\n";
    }

    //A function to print data in DS
    void print()
    {

        for (int i = 0; i < length; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

    // destructor
    ~vec()
    {
        delete[] arr;
    }
};

int main()
{
    vec v(10,0);
    for(int i=0; i<10; i++) v.insert(i,i);
    v.print();
    v.pop_back();
    v.print();
    
    cout<<v[0]<<endl;
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/concatenation-of-array/
    */
}
