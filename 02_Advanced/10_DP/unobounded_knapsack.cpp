#include<bits/stdc++.h>
#define int long long int

using namespace std;

// Dynamic Programming Solution
// Time: O(n * m), Space: O(n * m)
// Where n is the number of items & m is the capacity.
int dp(vector<int>& profit, vector<int>& weight, int capacity) 
{
    int N = profit.size(), M = capacity;
    vector<vector<int> > dp(N, vector<int>(M + 1, 0));

    // Fill the first column and row to reduce edge cases
    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
    }
    for (int c = 0; c <= M; c++) {
        if (weight[0] <= c) {
            dp[0][c] = profit[0];
        } 
    }

    for (int i = 1; i < N; i++) 
    {
        for (int c = 1; c <= M; c++) 
        {
            int skip = dp[i-1][c];
            int include = 0;
            if (c - weight[i] >= 0) include = profit[i] + dp[i][c - weight[i]];
            dp[i][c] = max(include, skip);
        }
    }
    return dp[N-1][M];
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   
   cout<<(float)clock() / CLOCKS_PER_SEC<<endl;
   return 0;
}
/*
https://leetcode.com/problems/coin-change/
https://leetcode.com/problems/coin-change-ii/
https://leetcode.com/problems/minimum-cost-for-tickets/
*/