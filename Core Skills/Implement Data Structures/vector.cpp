#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
private:
    int *arr;
    int capacity = 2, length = 0;

public:
    DynamicArray() {
        arr = (int*)malloc(sizeof(int)*capacity);
        arr[0] = 0;
        arr[1] = 0;
    }

    void resize() {
        capacity = capacity * 2;
        int * new_arr = (int*)malloc(sizeof(int)*capacity);
        for(int i=0; i<capacity; i++) new_arr[i] = 0;
        for(int i=0; i<length; i++) new_arr[i] = arr[i];
        delete arr;
        arr = new_arr;
    }

    void push_back(int n) {
        if(length == capacity) resize();
        arr[length++] = n;
    }

    void pop_back() {
        if(length > 0) length--;
    }

    void print() {
        for(int i=0; i<length; i++) cout<<arr[i]<<"\t";
        cout<<"\n";
    }
};

int main() {
    DynamicArray arr;
    arr.print();
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.print();
    arr.pop_back();
    arr.print();
}