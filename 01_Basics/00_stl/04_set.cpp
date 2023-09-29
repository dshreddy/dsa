#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<int> s = {0, 0, 1, 2, 3};

  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << "\t";
  cout << endl;

  s.erase(3); // can erase by value & by iterator

  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << "\t";
  cout << endl;

  cout << s.count(1) << endl;

  // s.find(x), s.lower_bound(x), s.upper_bound(x), s.erase(it)
}
