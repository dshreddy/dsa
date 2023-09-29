#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> stack;
  stack.push(0);
  stack.push(1);
  stack.push(2);

  while (!stack.empty()) {

    cout << stack.top() << endl;
    stack.pop();
  }
}
