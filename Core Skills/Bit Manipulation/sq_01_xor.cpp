#include<bits/stdc++.h>
#define int long long int
#define all(a) (a).begin() , (a).end()
#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<setw(2); cout<<endl;
#define tt int TESTCASE; cin>>TESTCASE; while(TESTCASE--)
#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]

using namespace std;
const int mod = 1e18;
const int inf = 1e18;

//https://www.codechef.com/problems/XOR2

void solve()
{
    /*
        The logic is we can always make an element 0 by xor'ing with itself 
        & 0^something=something

        consider 1 2 4
         1 2 4 ===> make 1st element 0 by xoring a[0],a[1] with a[0] ==> 0 1^2 4
         make 2nd element 0 by xoring a[1],a[2] with a[1] ==> 0 0 1^2^4
         make all elements same  by xoring a[0],a[1] with a value equal to a[2] ==> 1^2^4 1^2^4 1^2^4

         Now if the number of element in the array are odd then apart from last there will be even number of 0's in the array
         we will take them 2 at a time and xor with the x=last element making all elements as the last element

         So to solve this we have to find xor of all elements, and if it is 0 then we are done 
         If not then we have to see if n%2==0 or not 
    */
    int n; cin>>n;
    
    vector<int>a(n,0); 
    arrin(a,n);
    
    int x=0;
    for(int i=0;i<n;i++) x^=a[i];
    
    if(n%2==0 && x!=0) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   tt solve();
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}