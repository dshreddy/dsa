#include <bits/stdc++.h>
using namespace std;

// Implementing a stack is trivial using a dynamic array (which we implemented
// earlier).
class Stack {
private:
  vector<int> v;

public:
  Stack(){};
  // O(1)
  int top() {

    if (v.size() > 0)
      return v[v.size() - 1];
    else {

      cout << "Error : No top for empty stack";
      return INT_MIN;
    }
  }
  // O(1)
  void push(int n) { v.push_back(n); }
  // O(1)
  void pop() {

    if (v.size() > 0)
      v.pop_back();
    else
      cout << "Error : Popping from empty stack\n";
  }
  // O(1)
  bool isEmpty() { return v.size() == 0; }
};
int main() {
  Stack stack;
  stack.push(72);

  cout << stack.isEmpty() << endl;
  cout << stack.top() << endl;

  stack.pop();

  cout << stack.isEmpty() << endl;
  /*
  SUGGESTED PROBLEMS
  https://leetcode.com/problems/baseball-game/
  https://leetcode.com/problems/valid-parentheses/
  https://leetcode.com/problems/min-stack/
  */
}
