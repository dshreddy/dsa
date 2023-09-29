#include <bits/stdc++.h>
#define int long long int
using namespace std;

class StaticArray {

private:
  int *arr;
  int capacity;
  int length;

public:
  // constructor
  StaticArray(int capacity) {

    this->capacity = capacity;
    this->length = 0;
    this->arr = new int[capacity];
  }

  // destructor
  ~StaticArray() { delete[] arr; }

  // O(1)
  void insertEnd(int n) {

    if (length < capacity)
      arr[length++] = n;
    else
      cout << "Error : Array size if full\n";
  }

  // O(1)
  void removeEnd() {

    if (length > 0)
      arr[--length] = 0;
    else
      cout << "Error : Removing from an empty array\n";
  }

  // O(n)
  void insertMiddle(int i, int n) {

    if (i >= 0 && i <= length && length < capacity) {

      for (int index = length - 1; index >= i; index--)
        arr[index + 1] = arr[index];
      arr[i] = n;
      length++;
    } else
      cout << "Error\n";
  }

  // O(n)
  void removeMiddle(int i) {

    if (i >= 0 && i < length) {

      for (int index = i + 1; index < length; index++)
        arr[index - 1] = arr[index];
      arr[--length] = 0;
    } else
      cout << "Error\n";
  }

  // O(n)
  void printArray() {

    for (int i = 0; i < length; i++)
      cout << arr[i] << "\t";
    cout << endl;
  }
};

signed main() {

  StaticArray arr(10);

  arr.insertEnd(0);
  arr.insertEnd(1);
  arr.insertEnd(2);
  arr.insertEnd(3);
  arr.printArray();
  arr.removeEnd();
  arr.printArray();

  /*
 SUGGESTED PROBLEMS
  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  https://leetcode.com/problems/remove-element/
  https://leetcode.com/problems/shuffle-the-array/
 */

  return 0;
}
