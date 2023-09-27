#include<bits/stdc++.h>
#define int long long int
using namespace std;

class A{
    int x;
public:
    A(int y) : x(y) {}

    friend void f(A &obj);
};

void f(A &obj)
{
    cout<<obj.x<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   A obj(2);
   f(obj);

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}
