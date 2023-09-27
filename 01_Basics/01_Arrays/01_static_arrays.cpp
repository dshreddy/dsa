#include <bits/stdc++.h>
using namespace std;
 
// length is the number of 'real' values in arr.
// capacity is the size (aka memory allocated for the fixed size array).

void insertEnd(int arr[], int n, int length, int capacity);     //O(1)
// Inserts n into arr at the next open position. 

void removeEnd(int arr[], int length);                          //O(1)
// Removes from the last position in the array if the array is not empty (i.e. length is non-zero).

void insertMiddle(int arr[], int i, int n, int length);         //O(n)
// Inserts n into index i after shifting elements to the right. Assuming i is a valid index and arr is not full.

void removeMiddle(int arr[], int i, int length);                //O(n)
// Removes value at index i before shifting elements to the left. Assuming i is a valid index.

void printArr(int arr[], int capacity);                         //O(n)
//Prints Array

int main()
{
    int arr[10];
    insertEnd(arr,0,0,10);
    insertEnd(arr,1,1,10);
    insertEnd(arr,2,2,10);
    insertEnd(arr,3,3,10);
    printArr(arr,4);
    removeEnd(arr,4);
    printArr(arr,4);

    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    https://leetcode.com/problems/remove-element/
    https://leetcode.com/problems/shuffle-the-array/
    */
}
void insertEnd(int arr[], int n, int length, int capacity) {
    
    if (length < capacity) {
        arr[length] = n;
    }
}
void removeEnd(int arr[], int length) {
    if (length > 0) {
        arr[length - 1] = 0;
    }
}
void insertMiddle(int arr[], int i, int n, int length) {
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }   
    arr[i] = n;
}
void removeMiddle(int arr[], int i, int length) {
    for (int index = i + 1; index < length; index++) {
        arr[index - 1] = arr[index];
    }
}
void printArr(int arr[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
