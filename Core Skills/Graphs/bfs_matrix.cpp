#include<bits/stdc++.h>
using namespace std;

// Shortest path from top left to bottom right
int bfs(vector<vector<int> >& grid) 
{
    int ROWS = grid.size(), COLS = grid[0].size();
    
    vector<vector<int> > visit(4, vector<int>(4));
    queue<pair<int, int> > queue;

    queue.push(pair<int, int>(0, 0));
    visit[0][0] = 1;

    int length = 0;

    while (queue.size()) 
    {
        int l = queue.size();
        for (int i = 0; i < l; i++) 
        {
            pair<int, int> curPair = queue.front();
            queue.pop();

            int r = curPair.first, c = curPair.second;
            if (r == ROWS - 1 && c == COLS - 1) return length;

            // We can directly build the four neighbors
            int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};

            for (int j = 0; j < 4; j++) 
            {
                int newR = neighbors[j][0], newC = neighbors[j][1];

                if (min(newR, newC) < 0 || newR == ROWS || newC == COLS || visit[newR][newC] || grid[newR][newC]) continue;
                queue.push(pair<int, int>(newR, newC));
                visit[newR][newC] = 1;
            }
        }
        length++;
    }
    return length;
}
int main()
{
    /*
    SUGGESTED PROBLEMS
    https://leetcode.com/problems/shortest-path-in-binary-matrix/
    https://leetcode.com/problems/rotting-oranges/
    */
}