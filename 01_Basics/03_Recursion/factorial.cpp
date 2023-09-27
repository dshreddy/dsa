#include<bits/stdc++.h>
#define int long long int

using namespace std;

// Recursive implementation of n! (n-factorial) calculation
int factorial(int n) {
    // Base case: n = 0 or 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!
    return n * factorial(n - 1);
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   cout<<factorial(5)<<endl;
   
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}