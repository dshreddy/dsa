#include<bits/stdc++.h>
using namespace std;

// Count paths (backtracking)
int dfs(vector<vector<int> >& grid, int r, int c, vector<vector<int> >& visit) 
{
    int ROWS = grid.size(), COLS = grid[0].size();

    if (min(r, c) < 0 || r == ROWS || c == COLS || visit[r][c] || grid[r][c]) return 0;
    if (r == ROWS - 1 && c == COLS - 1) return 1;

    visit[r][c] = 1;

    int count = 0;
    count += dfs(grid, r + 1, c, visit);
    count += dfs(grid, r - 1, c, visit);
    count += dfs(grid, r, c + 1, visit);
    count += dfs(grid, r, c - 1, visit);

    visit[r][c] = 0;
    return count;
}
int main()
{
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/number-of-islands/
    https://leetcode.com/problems/max-area-of-island/
    */
}
