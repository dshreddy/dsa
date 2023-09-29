#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);

  cout << q.size() << endl;
  cout << q.front() << endl;
  cout << q.back() << endl;
  q.pop();
  cout << q.front() << endl;
}
