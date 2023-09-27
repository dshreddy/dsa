#include<bits/stdc++.h>
#define int long long int

using namespace std;

void solve(int i,int n, int k, vector<int>v) {

    if(v.size()==k) 
    {
        for(int i=0; i<k; i++) cout<<v[i]<<"\t";
        cout<<endl;
        return;
    }

    for(int j=i; j<=n; j++) {

        v.push_back(j);
        solve(j+1,n,k,v);
        v.pop_back();
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//    int t; cin>>t;
//    while(t--)

   int n = 5;
   int k = 2;
   vector<int>v1;

   solve(1,5,2,v1);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}
/*
https://leetcode.com/problems/combinations/
Solution: https://youtu.be/q0s6m7AiM7o

https://leetcode.com/problems/combination-sum/
Solution: https://youtu.be/GBKI9VSKdGg

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Solution: https://youtu.be/0snEunUacZY
*/