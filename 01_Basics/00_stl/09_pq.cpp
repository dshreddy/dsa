#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<int, vector<int>, greater<int>> minHeap;

  minHeap.push(10);
  minHeap.push(20);
  minHeap.push(5);

  cout << "smallest element in min heap before popping : " << minHeap.top()
       << endl;
  minHeap.pop();
  cout << "smallest element in min heap after popping : " << minHeap.top()
       << endl;

  priority_queue<int, vector<int>, less<int>> maxHeap;

  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(5);

  cout << "greatest element in max heap before popping : " << maxHeap.top()
       << endl;
  maxHeap.pop();
  cout << "greatest element in max heap after popping : " << maxHeap.top()
       << endl;

  return 0;
}
