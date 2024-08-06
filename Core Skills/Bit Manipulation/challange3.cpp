#include<bits/stdc++.h>
#define int long long int
#define all(a) (a).begin() , (a).end()
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<setw(2); cout<<endl;
#define tt int TESTCASE; cin>>TESTCASE; while(TESTCASE--)
#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]

using namespace std;
const int mod = 1e18;
const int inf = 1e18;

int Get_Bit(int n,int pos)
{
    /*
          3 2 1 0
        n=1 0 1 1
        pos=2
        1<<i=0100 
        n & (1<<pos) = 0000
    */
   return ((n & (1<<pos)) != 0);
}

void solve()
{
    // Prrint All subsets of a given set {a,b,c}
    /*
            {a,b,c}  size = 3 Total Subsets = 2^3 = 1<<3, let's number them from 0 to 2^3-1

            cba
        0   000     {}
        1   001     {a}
        2   010     {b}
        3   011     {b,a}
        4   100     {c}
        5   101     {c,a}
        6   110     {c,b}
        7   111     {c,b,a}
        
        Time Complexity O(2^n * n)
    */
   char arr[]={'a','b','c'};
   int n=sizeof(arr)/sizeof(arr[0]);
    
   for(int i=0;i<(1<<n);i++)
   {
      //i will be a n bit number
      for(int j=n-1;j>=0;j--)
      {
        if(Get_Bit(i,j)) cout<<arr[j]<<"\t";
        else cout<<"\t";
      }
      cout<<endl;
   }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}