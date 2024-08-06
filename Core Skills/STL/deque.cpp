#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<int> q;
  q.push_front(10);
  q.push_front(20);
  q.push_front(30);
  q.push_back(-10);
  q.push_back(-20);
  q.push_back(-30);

  for (auto it = q.begin(); it != q.end(); it++)
    cout << *it << "\t";
  cout << endl;

  q.pop_back();
  q.pop_front();

  for (auto it = q.begin(); it != q.end(); it++)
    cout << *it << "\t";
  cout << endl;
}
