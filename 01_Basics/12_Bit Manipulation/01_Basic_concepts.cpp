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
int Set_Bit(int n,int pos)
{
    /*
          3 2 1 0
        n=1 0 1 1
        pos=2
        1<<i=0100 
        n | (1<<pos) = 1111
    */
    return (n | (1<<pos));
}
int Clear_Bit(int n,int pos)
{
    /*
          3 2 1 0
        n=1 0 1 0
        pos=2
        1<<i=0100 
        ~(1<<i)=1011
        n & (~(1<<i)) = 1010
    */
    return (n & (~(1<<pos)));
}
int Update_Bit(int n,int pos,int val)
{
    if(val==0)  return Clear_Bit(n,pos);
    else return Set_Bit(n,pos);
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}