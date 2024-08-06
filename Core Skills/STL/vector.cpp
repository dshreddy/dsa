#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

struct node {
  int data;
  struct node *nxt;
};

signed main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<string> v1;
  vector<vector<int>> v2;
  vector<struct node *> v3;

  for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << "\t";
  cout << endl;

  // v.push_back(10);
  //  for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  //  cout<<endl;

  // v.pop_back();
  //  for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  //  cout<<endl;

  // v.erase(v.begin()+4); //erases the fifth element of the vector v
  // for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  // cout<<endl;

  // Removes the elements in the range from start to end inclusive of the start
  // and exclusive of the end.
  //  v.erase(v.begin()+2,v.begin()+5);
  //  for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  //  cout<<endl;

  // return an iterator to the position of 1st smallest element >=  x in
  // lower_bound(v.begin(), v.end(), x)
  cout << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;

  // return an iterator to the position of 1st smallest element > x in
  // lower_bound(v.begin(), v.end(), x)
  cout << upper_bound(v.begin(), v.end(), 7) - v.begin() << endl;

  // v.resize(5);
  // for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  // cout<<endl;

  // swap(v[0], v[1]);
  // for(auto it=v.begin(); it!=v.end(); it++) cout<<*it<<"\t";
  // cout<<endl;

  v.clear();
  return 0;
}
