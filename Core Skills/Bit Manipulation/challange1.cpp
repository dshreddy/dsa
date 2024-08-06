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
    // Check if a given number is a power of 2
    /*
    Naive Approach : Divide number continously by 2 and if u end up with 1 then ans is yes

    Bit Manipulation Approach :

                IMPORATANT OBSERVATION
                3 2 1 0                     3 2 1 0
        n = 8 = 1 0 0 0             n = 6 = 0 1 1 0
      n-1 = 7 = 0 1 1 1           n-1 = 5 = 0 1 0 1

    To get n-1 from n in binary you have to find the the right most set bit / right most 1 and then flip all the bits from it to end
    Example 1 In case of 8 Right most set bit is at position 3 , starting from it flipping all bits gives you 7
    Example 2 In case of 6 Right most set bit is at position 1 , starting from it flipping all bits gives you 5
    */
   
    int n; cin>>n;
    if( (n & (n-1)) == 0) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}