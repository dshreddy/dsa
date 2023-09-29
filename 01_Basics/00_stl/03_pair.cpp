#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  pair<int, int> p = {1, 2};
  // cout<<p.first<<"\t"<<p.second<<endl;

  // an array of 5 pairs (not so useful often)
  pair<int, int> pa[5];

  vector<pair<int, int>> v = {{1, 2}, {-1, 2}, {2, 3}, {4, 5}, {-2, 2}};

  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << "," << v[i].second << "\t";
  cout << endl;

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << "," << v[i].second << "\t";
  cout << endl;
}
