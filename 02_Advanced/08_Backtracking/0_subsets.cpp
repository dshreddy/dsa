#include<bits/stdc++.h>
#define int long long int

using namespace std;

void solve(vector<int>set_,vector<int>subset) 
{

     if(set_.size()==0) 
     {
       for(int i=0; i<subset.size(); i++) cout<<subset[i]<<"\t";
       cout<<endl;
       return;
     }

     int t = set_[0];
     set_.erase(set_.begin());

     //don't chose 
     solve(set_,subset);

     //chose
     subset.push_back(t);
     solve(set_,subset);
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   vector<int>v = {1,2,3};
   
   vector<int>s;
   solve(v,s);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}
/*
https://leetcode.com/problems/subsets/
Solution: https://youtu.be/REOH22Xwdkk

https://leetcode.com/problems/subsets-ii/
Solution: https://youtu.be/Vn2v6ajA7U0
*/