#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

bool dec_order(pair<int, int> p1, pair<int, int> p2) {

  return (p1.first > p2.first)
             ? (1)
             : ((p1.first == p2.first) ? (p1.second > p2.second) : (0));
}

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  pair<int, int> p[3];

  p[0] = {1, 2};
  p[1] = {3, 4};
  p[2] = {-1, 2};

  sort(p, p + 3, dec_order);

  for (auto i : p)
    cout << "(" << i.first << "," << i.second << ")"
         << "\t";
  cout << endl;

  return 0;
}
