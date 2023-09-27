#include<bits/stdc++.h>
#define int long long int
#define all(a) (a).begin() , (a).end()
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<setw(2); cout<<endl;
#define tt int TESTCASE; cin>>TESTCASE; while(TESTCASE--)
#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]

using namespace std;
const int mod = 1e18;
const int inf = 1e18;

int get_bit(int n,int pos)
{
    return ((n&(1<<pos)) != 0);
}

void solve()
{
    //Programme to find a unique number in an array where except 1 element the rest all are pepeated twice
    /*
        {2,4,6,7,4,5,6,2}
        previous prroach will give you 7^5
        7 = 111
        5 = 101
        -------
      7^5 = 010
      If we know the position of a set bit in a^b where a,b are unique, we know only one of a,b has 1 at that position (0^1=1,1^0=1)
      So we will take all elements which has 1 at that position and xor of those gives you 1st unique
    */
    int n,a_xor_b=0; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        a_xor_b^=v[i];
    }

    int set_bit = 0,pos=-1;
    while(set_bit != 1)
    {
        pos++;
        set_bit = get_bit(a_xor_b,pos);
    }

    int a = 0;
    for(int i=0;i<n;i++) if(get_bit(v[i],pos)) a^=v[i];
    
    int b = a_xor_b ^ a;

    cout<<a<<"\t"<<b<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}