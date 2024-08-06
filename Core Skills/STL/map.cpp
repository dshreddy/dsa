#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // elements are stored in sorted order of keys
  unordered_map<int, int> m;
  m[1] = 2;
  m[0] = 3;
  for (pair<int, int> p : m)
    cout << p.first << "-->" << p.second << endl;
}
