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
    //Programme to find a unique number in an array where except 1 element the rest all are pepeated 3 times
    /*
        { 2  , 2 , 2 , 4 , 6 , 6 , 6 }
         010  010 010 100 110 110 110

        initialize an array of size 64 and fill it with the number of elements having one at that index
        arr[64] = {0,6,4,0,0,0,....,0}
        do modulo 3 
        arr[64] = {0,0,1,0,0,.....,0}
        reverse it and covert to decimal
    */
   int arr[]={2,2,2,4,6,6,6};
   int n=sizeof(arr)/sizeof(arr[0]);

   int bits[64]={0};
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<32;j++)
        {
            if(get_bit(arr[i],j)) 
            {
                bits[j]++;
                //cout<<arr[i]<<" "<<j<<endl;
                bits[j]%=3;
            }
        }
   }
   //for(int j=0;j<64;j++) cout<<bits[j]<<endl;

   int ans=0;
   for(int j=0;j<64;j++)
   {
        if(bits[j]==1)
        {
            //cout<<bits[j]<<" "<<j<<endl;
            ans+=pow(2,j);
        }
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