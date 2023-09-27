#include<bits/stdc++.h>
#define int long long int
#define all(a) (a).begin() , (a).end()
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<setw(2); cout<<endl;
#define tt int TESTCASE; cin>>TESTCASE; while(TESTCASE--)
#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]

using namespace std;
const int mod = 1e18;
const int inf = 1e18;

void solve()
{
    //Programme to find a unique number in an array where except 1 element the rest all are pepeated twice
    /*
       0^0=0
       1^1=0
       Therefore a^a=0
       0^1=1
       0^0=0
       Therefore 0^something=something 
       (a^b)^c=a^(b^c)
    */
    int n,ans=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        ans^=v[i];
    }
    cout<<ans<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}