#include<bits/stdc++.h>
#define int long long int
using namespace std;

//O(2^n)
int fibonacci(int n) 
{
    // Base case: n = 0 or 1
    if (n <= 1) return n;

    // Recursive case: fib(n) = fib(n - 1) + fib(n - 1)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   for(int i=0; i<10; i++) cout<<fibonacci(i)<<"\t";
   cout<<endl;
   
   /*

   SUGGESTED PROBLEMS
    https://leetcode.com/problems/fibonacci-number/
    https://leetcode.com/problems/climbing-stairs/
   */

   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}