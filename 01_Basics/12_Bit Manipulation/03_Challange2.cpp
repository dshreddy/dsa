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
    //Programme to find number of 1's in the binary representation of a number
    /*
    Bit Manipulation Approach :

                                        IMPORATANT OBSERVATION
                 4 3 2 1 0                   4 3 2 1 0                      4 3 2 1 0              
        n = 19 = 1 0 0 1 1          n = 18 = 1 0 0 1 0             n = 16 = 1 0 0 0 0
      n-1 = 18 = 1 0 0 1 0        n-1 = 17 = 1 0 0 0 1           n-1 = 15 = 0 1 1 1 1
        --------------------        --------------------           --------------------
  n & n-1 = 18 = 1 0 0 1 0    n & n-1 = 16 = 1 0 0 0 0       n & n-1 = 16 = 0 0 0 0 0

    n & n-1 has same bits upto right most set bit & the rest as inverse starting from right most set bit
    so doing bit wise and gives the right part as it is and left part 0
    o the number of times we are able to do this is the answer
    */
   int n; cin>>n;
   int count=0;
   while(n!=0)
   {
    n=n&(n-1);
    count++;
   }
   cout<<count<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}