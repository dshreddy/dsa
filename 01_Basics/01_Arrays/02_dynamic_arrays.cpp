#include <bits/stdc++.h>
#define int long long int
using namespace std;

class DynamicArray {
private:
  int capacity; // maximum capacity of the array
  int length;   // number of elements currently in the array
  int *arr;     // pointer to the dynamic array

public:
  // Constructor to create an empty dynamic array with a default capacity of 2
  DynamicArray() : capacity(2), length(0), arr(new int[2]) {
    arr[0] = 0;
    arr[1] = 0;
  }

  // Constructor to initialize an array of size = size with each element = 0
  DynamicArray(int size) : capacity(size), length(size), arr(new int[size]) {

    if (size >= 0)
      for (int i = 0; i < size; i++)
        arr[i] = 0;
    else {
      cout << "Negative size allocation is not possible" << endl;
      capacity = 2;
      length = 0;
      arr = new int[2];
    }
  }

  // Constructor to initialize an array of size = size with each element = num
  DynamicArray(int size, int num)
      : capacity(size), length(size), arr(new int[size]) {

    if (size >= 0)
      for (int i = 0; i < size; i++)
        arr[i] = num;
    else {
      cout << "Negative size allocation is not possible" << endl;
      capacity = 2;
      length = 0;
      arr = new int[2];
    }
  }

  // Destructor to free the dynamically allocated memory
  ~DynamicArray() { delete[] arr; }

  // Function to double the size of the array when it's full
  void resize() {

    capacity = capacity * 2;
    int *new_arr = new int[capacity];

    for (int i = 0; i < length; i++)
      new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
  }

  void push_back(int num) {

    if (length == capacity)
      resize();
    arr[length++] = num;
  }

  void pop_back() {

    if (length > 0)
      length--;
    else
      cout << "Error : No elements to pop" << endl;
  }

  // Operator overloading to access elements in the array like an array
  int operator[](int i) {

    if (i >= 0 && i < length)
      return arr[i];
    else
      cout << "Error : Out of Bounds" << endl;
    return INT_MIN;
  }

  void insert(int i, int num) {

    if (i >= 0 && i < length)
      arr[i] = num;
    else
      cout << "Error : Out of Bounds" << endl;
  }

  void print() {

    for (int i = 0; i < length; i++)
      cout << arr[i] << "\t";
    cout << endl;
  }
};

signed main() {

  DynamicArray arr(10, 0);

  for (int i = 0; i < 10; i++)
    arr.insert(i, i);

  arr.print();
  arr.pop_back();
  arr.print();

  cout << arr[0] << endl;

  // SUGGESTED PROBLEM : https://leetcode.com/problems/concatenation-of-array/
  return 0;
}
